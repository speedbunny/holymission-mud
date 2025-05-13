/*
 * File_date compare program.
 */

#define DEBUG 0

inherit "/obj/thing";

/*########## global variables to save #########*/
mixed* file_date;


/*########### global variables not to be saved #########*/
static int new,changed,ok;
static string *fnew, *fchange;


/*########### prototypes ##############*/
int check_1(string *dir, int idx);


void reset(int arg)
{
	if(arg) return;
	::reset(arg);

	set_short("file compare");
	set_name("fcomp");
	set_alias("file");
	new = ok = changed = 0;

}

void init()
{
	::init();
	add_action("a_check","fcheck",1);
	add_action("a_save","fsave",1);
}

int a_save(string str)
{
string *dir;
int i;
	ok = 0;
	if(!strlen(str)) 
	{
//		write("Und so soll das funktionieren?\n");
		str = "/"+this_player()->query_path();
//		return 1;
	}
	
	if(sizeof(get_dir(str)) != 1)
	{
		write("Falsche eingabe, damit kann ich nix anfangen.\n");
		return 1;
	}

	dir = get_dir(str+"/.");
	if(DEBUG) write("SIZEOF dir: "+sizeof(dir)+"\n");
	for(i=0;i<sizeof(dir);i++)
	{
		if(DEBUG) write("INDEX: "+i+" "+dir[i]+"\n");
		if(!i) file_date = ({ dir[i], ftime(dir[i]) });
		else file_date += ({  dir[i] ,  ftime( dir[i] ) });
		ok++;
	}
	if(DEBUG) write("SIZEOF file_date: "+sizeof(file_date)+"\n");
	if(str[0] != '/') str=this_player()->query_path()+"/"+str;
	write(ok+" Files in dir: "+str+"\n");
	save_object(str+"/FILE_DATE");
	return 1;
}

int a_check(string str)
{
string *dir;
int i,sz_i;

	ok = new = changed = 0;
	fnew = ({});
	fchange = ({});
	if(!strlen(str))
	{
//		write("So geht das net.\n");
//		return 1;
		str = "/"+this_player()->query_path();
	}

	if(sizeof(get_dir(str)) != 1)
	{
		write("Na, damit kann ich nix anfangen.\n");
		return 1;
	}

	if(str[0] != '/') str = this_player()->query_path()+"/"+str;
	write("Processing: "+str+"\n");
	restore_object(str+"/FILE_DATE");
	dir = get_dir(str+"/.");
	if(sizeof(dir) != sizeof(file_date)/2)
	{
		if(DEBUG) write("OLD: "+sizeof(dir)+ "NEU: "+sizeof(file_date)/2+"\n");
		write("Tja, die Anzahl der files stimmt net mehr :-(\n");
		/* 
		 * FCOMP
		 */
		check_1(dir,0);
	}
	else	// Anzahl der Files stimmt
	{
		sz_i = sizeof(dir);
		for(i=0;i<sz_i;i++)
		{	
			if(DEBUG) write("Checking: "+dir[i]+"  "+file_date[i*2]+"\n");
			if ( dir[i] != file_date[i*2])
			{
				write("Falscher Name "+dir[i]+" "+file_date[i*2]+"\n"); 
				check_1(dir,i);
				break;
			}
			if (ftime(dir[i]) != file_date[i*2+1] )
			{
				write(dir[i]+" Zeit passt net: "+ctime(ftime(dir[i]))+" "+ctime(file_date[i*2+1])+"\n");
				changed++;
				fchange += ({dir[i]});
				
			}
			else ok++;
		}
	}
	write("Files ok: \t"+ok+"\n");
	write("\nFiles new: \t"+new+"\n");
	for(i=sizeof(fnew)-1;i>=0;i--) write(fnew[i]+"\t");
	write("\nFiles changed:\t"+changed+"\n");
	for(i=sizeof(fchange)-1;i>=0;i--) write(fchange[i]+"\t");
	write("\n");
	return 1;
}

int check_1(string *dir, int idx)
{	
int i,j,sz_i;
	sz_i = sizeof(dir);
	for(i=idx;i<sz_i;i++)
	{
		if((j=member_array(dir[i],file_date)) != -1)
		{
			if(ftime(dir[i]) == file_date[j+1])
			{
				if(DEBUG) write(dir[i]+" OK.\n");
				ok++;
			}
			else
			{
				write(dir[i]+" CHANGED.\n");
				write(ctime(ftime(dir[i]))+"\t"+ctime(file_date[j+1])+"\n");
				changed++;
				fchange += ({dir[i]});
			}
		}
		else
		{
			write(dir[i]+" MUST BE NEW.\n");
			new++;
			fnew += ({dir[i]});
		}
	}
}
			
	

	
