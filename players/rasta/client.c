#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "io.h"
#include "client.h"
#include "config.h"
#include "struct.h"

char *filebuffer;
struct mtpheader *header;
struct mtpmessage *mtpm;

#define BUFSIZE 2048
char mtphost[BUFSIZE];
int mtpport;

char thisgame[BUFSIZE];

/*------------------------------------------------------------------------*/

main(argc,argv)
int argc;
char **argv;
{
int i;

        thisgame[0] = '\0';
        open_all();

	if (argc==1)
		print_help();

	for (i=1 ; i<argc ; i++)
	{
		if (*argv[i]=='-')		/* Argument ist ein Flag */
			parse_flag (argv[i]);
		else				/* Argument ist ein File */
		        transmit (argv[i]);
	}
        close_all();
}


/*------------------------------------------------------------------------*/

void print_help()
{
	printf ("USAGE: mtp [-r] [-g<game>] file1 file2 ...\n");
	printf ("            -r: Receive file from MUD\n");
	printf ("      -g<game>: Specify the target MUD\n");
	close_all();
	exit (2);
}

/*------------------------------------------------------------------------*/

void parse_flag (arg)
char *arg;

{
int i;
char *point;

	for (i=1 ; i<strlen(arg) ; i++)
	{
		switch (arg[i])
		{
			case 'o' :	header->flags|=OVERWRITE;
					break;

			case 'g' :	point= &arg[i+1];
					strcpy(thisgame, point);
					get_params(thisgame, mtphost, &mtpport,
						   header->player, header->passwd);
					return;
					break;

			case 'r' :	header->flags|=RECEIVE;
					break;

			default :	print_help();
					break;
		}
	}
}

/*------------------------------------------------------------------------*/

void transmit(path)
char *path;
{
int fh,sh,bytes;
char tmp[5];

	header->flags|=VERSION_TWO;
	if (header->flags&RECEIVE)
	{
		printf ("Trying %s ... please be patient !\n",mtphost);
		get_file (path,header);
		return;
	}

	if (check_directory(path))
	{
		printf ("%s is a directory (not transmitted) !\n",path);
		return;
	}

	fh = open (path,O_RDONLY,4);
	if (fh<1)
	{
		fh = open (cut_path(path),O_RDONLY,4);
		if (fh<1)
		{
			fprintf (stderr,"Error: File '%s' not found or accessible...\n",path);
			close_all();
			exit(0);
		}
	}

	printf ("Trying %s ... please be patient !\n",mtphost);

	bytes = read (fh,filebuffer,MAX_FILELENGTH);
	if (bytes>=MAX_FILELENGTH)
	{
		fprintf (stderr,"Error: File too large. Maximum filesize is %d Bytes !\n",MAX_FILELENGTH);
		close_all();
		exit(0);
	}
	close(fh);

#ifdef ULTRIX
	SWAP (bytes);
	SWAP (header->flags);
#endif
	header->filelength=bytes;

	if (*header->directory!=(char)0)
	{
		strcpy (header->filename,header->directory);
		cat_path (header->filename,cut_path(path));
	}
	else
	{
		strcpy (header->filename,path);
	}

	if (!(sh=connect_socket(mtphost,mtpport)))
	{
		printf ("No connection to MTPserver. Transmission failed !\n");
		exit(0);
	}

	strcpy (tmp,"@");
	safe_write (sh,tmp,1);

	if (!(safe_write (sh,(char *)header,sizeof(struct mtpheader))))
	{
		printf ("Couldn't write MTPheader ... aborting\n");
		close_all();
		exit (0);
	}

#ifdef ULTRIX
	SWAP(header->filelength);
#endif

	if(!(read_message(sh,mtpm)))
		return;

	if (!(safe_write (sh,filebuffer,header->filelength)))
	{
		printf ("\nCouldn't transmit datafile ... aborted.\n");
		close_all();
		exit (0);
	}

	if (!(read_message(sh,mtpm)))
		return;
}

/*-------------------------------------------------------------------------*/

void open_all()

{

	header = (struct mtpheader *) introduce (sizeof(struct mtpheader));
	filebuffer = introduce(MAX_FILELENGTH+1);
	mtpm = (struct mtpmessage *) introduce (sizeof(struct mtpmessage));

	get_params(thisgame,
		   mtphost, &mtpport, header->player, header->passwd);
	
}

/*-------------------------------------------------------------------------*/

void close_all()

{
	dismiss (header);
	dismiss(filebuffer);
	dismiss(mtpm);
}

