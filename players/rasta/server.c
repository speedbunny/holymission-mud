#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "io.h"
#include "server.h"
#include "config.h"
#include "struct.h"
#include "server.h"

char *filebuffer;
struct mtpheader *header;
struct mtpmessage *mtpm;

#define BUFSIZE 2048
char mtphost[BUFSIZE];
int mtpport=MTPPORT;
int level;

/*------------------------------------------------------------------------*/

main(argc,argv)
     char *argv[];
     int argc;
{
int fh,sh,ok,cycle;
char *path,tmp[200],tmp2[100];

	cycle = 0;
	for (;;)
	{
	if (fork()==0)
	{
	gethostname(mtphost, BUFSIZE);
	if (argc == 2)
		mtpport = atoi(argv[1]);
  
	open_all();
	init_server();

	sh=0;

	for (;;)
	{
	if (sh) close (sh);

	if (!(sh=create_socket(mtpport)))
	{
		close_all();
		exit(0);
	}

	safe_read (sh,tmp,1);
	if (*tmp!='@') continue;

	if (!(safe_read (sh,header,sizeof(struct mtpheader))))
		continue;

	level = grant_access(header);;
	if (level < 21)
	{
		sprintf(tmp,"Connected to MTPserver V1.4 at %s.\nPermission denied for user '%s'.\n",mtphost,header->player);
		write_message(sh,mtpm,tmp,1);
		continue;
	}

	sprintf (tmp,"Connected to MTPserver V1.4 at %s.\n",mtphost);
	path = build_path (header,level);
	ok = illegal_path (path,level);
	switch (ok)
	{
		case 0 :	sprintf (tmp2,"Transmission of file %s (%d Bytes) ...",cut_path(header->filename),header->filelength);
				break;

		case 1 :	sprintf (tmp2,"Illegal characters in filename ! Aborted !\n");
				break;

		case 2 :	sprintf (tmp2,"No write permission in outer areas ! Aborted !\n");
				break;

		case 3 :	sprintf (tmp2,"This file is read protected ! Sorry !\n");
				break;
	}
	strcat (tmp,tmp2);
	if ((ok==0)&&(*header->filename=='/')&&((header->flags&RECEIVE)==0)
	           &&((header->flags&OVERWRITE)==0))
	{
		sprintf(tmp,"You are going to write in outer area ! To proceed, add -o !\n");
		ok=1;
	}

	if (ok>0)
	{
		write_message (sh,mtpm,tmp,1);
		continue;
	}

	if (check_directory(path))
	{
		strcat (tmp," aborted.\nDestination file %s is a directory !\n",path);
		write_message (sh,mtpm,tmp,1);
		continue;
	}

	if (header->flags&RECEIVE)
	{
		log_message (header);
		send_file (sh,path,header);
		continue;
	}

	fh = mtp_open (path,header);
	if (fh<1)
	{
		strcat (tmp," aborted.\nCouldn't write destination file (maybe already existing ?)\n");
		write_message (sh,mtpm,tmp,1);
		continue;
	}

	if (!(write_message(sh,mtpm,tmp)))
		continue;

	if (!(safe_read(sh,filebuffer,header->filelength)))
		continue;
	else
		sprintf (tmp," completed.\n");

	safe_write (fh,filebuffer,header->filelength);
	write_message(sh,mtpm,tmp,1);
	log_message (header);

	if (fh) close (fh);

	} /* main loop */
	}

	wait(0);
	cycle++;
	if (cycle>MAX_CYCLE)
		exit(1);
	sleep (2);
	if (sh) close (sh);
	}
}

/*-------------------------------------------------------------------------*/

void open_all()

{
	header = (struct mtpheader *) introduce (sizeof (struct mtpheader));
	filebuffer = introduce (MAX_FILELENGTH+1);
	mtpm = (struct mtpmessage *)introduce(sizeof(struct mtpmessage));
}

/*-------------------------------------------------------------------------*/

void close_all()

{
	dismiss (header);
	dismiss (filebuffer);
	dismiss (mtpm);
}

/*-------------------------------------------------------------------------*/

void init_server()

{
	strcpy (header->player,"MTPmaster");
	strcpy (header->filename,"MTPserver initialized");
	header->filelength = 0;
	header->flags = 0;
	log_message(header);
}

/*-------------------------------------------------------------------------*/

int grant_access (mtph)
struct mtpheader *mtph;

{
FILE *fd;
char passwd[20],tmp[500],tmp2[500];
int i,ok,level;

	ok = 0;
	level = 0;
	sprintf(tmp,"%s/players/%s.o",MUDPATH,mtph->player);
	if (!(fd = fopen (tmp,"r")))
		return 0;

	while (fscanf (fd,"%s",tmp)!=EOF)
	{
		if (strcmp(tmp,"level")==0)
			fscanf (fd,"%d",&level);

		if (strcmp(tmp,"password")==0)
		{
			fscanf (fd,"%s",tmp2);
			for (i=0;i<strlen(tmp2)-2;i++)
				passwd[i]=tmp2[i+1];
			passwd[i]=(char)0;
			if (strcmp(passwd,crypt(mtph->passwd,passwd))==0)
				ok = 1;
			else
				ok = 0;
		}
	}

	if (fd) fclose (fd);

	if (ok)
		return level;
	else
		return 0;
}

