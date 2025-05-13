/*
 * Author    : Galadriel.
 * Date      : 03-10-1992.
 * Version   : v3.1
 * Last work : 04-08-1993.
 * (c) YSY-SYS, the Netherlands.
 */

#define FILE    "tools/filetool"
#define TP       this_player()
#define TO       this_object()
#define IS_ME    TP->query_real_name()=="galadriel"
#define IS_OWNER creator(TO)==TP->query_real_name()
#define NO_OWNER creator(TO)==0
#define IS_ARCH  TP->query_archwiz()
#define IS_LORD  TP->query_lord()
#define IS_WIZ   TP->query_wizard()
#define IS_NEW   TP->query_newwiz() 
#define IS_APPR  TP->query_immortal()
/* Only Galadriel can give permission to newwiz */
#define IS_PERM  (IS_NEW)
#define SCREEN_WIDTH 79

int mode,logmode;
string load_name,logfile;
int tree_level, max_dir_entries;

id (str) { return str=="filetool" || str=="librarian" || str=="li"; }

short () { return "Galadriel's librarian (v3.1)"; }

long ()  { 
    write("This librarian is still learning new tricks... Known tricks are:\n\n");
    printf("%-*.2#s\n",SCREEN_WIDTH,
      "libmode - change mode of librarian\n"+
      "fc      - compare two files\n"+
      "ldir    - dir with extra '*' and '/'\n"+
      "fdir    - dump dir to a file\n"+
      "ddir    - deep dir, shows all subdirs\n"+
      "ltree   - tree of dir and all subdirs\n"+
      "lstr    - search string in files\n"+
      "repstr  - replace string in files\n"+
      "frepstr - same but logs old lines\n"+
      "lcp     - copy one file\n"+
      "mcp     - multicopy files to a dir\n"+
      "lmv     - rename or move a file\n"+
      "cleardir- remove all files in current dir\n"+
      "lhelp   - more help\n"
    );
    write("\nbuilt in filename-expander:\n"+
      "- If you dont specify path, I 'll add current path.\n"+
      "- I will replace '~/' with '/players/'.\n"+
      "- I will replace '&/' with '/players/"+TP->query_real_name()+"/'.\n"+
      "\n"+
      "...well thats it for today, but I keep learning!\n"+
      "If I do not function properly, please warn my boss :-)\n");
    /* no longer needed...
      if (NO_OWNER) {
	write("WARNING: Some file functions that do writing or deleting require\n"+
	      "that you are the owner of this tool. If you need these functions\n"+
	      "copy /tools/filetool.c to one of your own dirs, destruct this\n"+
	      "tool and clone the tool from your own dir.\n"+
	      "The autoload will automatic choose your own copy next time.\n");
      }
    */
    /*  if (IS_ME) {
	write(""
      +"testname                 - does tool decide wiztype correct?\n"
      +"testpar                  - do parameters work correct?\n"
      );
      }*/
}

init_arg() {
    string tmp1,tmp2;

    if (sscanf(file_name(this_object()),"%s#%s",tmp1,tmp2)==2)
	write("Your personal librarian arrives from "+tmp1+".\n");
    /* not needed anymore
      if (NO_OWNER) {
	write("The librarian tells you: I work better when you copy me to "+
	      "your own dir!\n");
      }
    */
}

void reset(int arg) {
    if (arg) return;
    if (!IS_PERM) {
	write("error in loading, contact Galadriel (or mail)\n");
	destruct(TO);
	return;
    }
    /* used to be 329 but is set down for the current eval-cost 75000 limit */
    max_dir_entries = 9999999;
}

init () {
    string tmp1,tmp2;

    mode = 2;
    logmode = 0;
    if (sscanf(file_name(this_object()),"%s#%s",tmp1,tmp2)==2) {
	load_name = tmp1+":";
    }
    add_action("do_set_mode","libmode");
    add_action("do_file_compare","fc");
    add_action("do_dir","ldir");
    add_action("do_deep_dir","ddir");
    add_action("do_ls_to_file","fdir");
    add_action("do_numbered_dir","ndir");
    add_action("do_list","ll");
    add_action("do_dir_tree","ltree");
    add_action("do_copy","lcp");
    add_action("do_temp_move","lmv");
    add_action("do_remove_file","cleardir");
    add_action("do_search_str","lstr");
    add_action("do_log_and_replace_str","frepstr");
    add_action("do_replace_str","repstr");
    add_action("do_multi_copy","mcp");
    add_action("do_send","libsend");
    add_action("do_update","libupdate");
    add_action("do_move","testmv");
    add_action("do_lib_help","lhelp");
    add_action("lib_fix_spaces","testspaces");
    add_action("lib_get_parameters","testpar");
    add_action("lib_file_name","testname");
    add_action("lib_max_dir_entries","maxdir");
}

get ()  { return 1; }  /* no get */
drop () { return 1; }
query_auto_load() { return load_name; }
/*
query_auto_load ()   { return "tools/filetool:"; }
*/

int lib_max_dir_entries(int arg) {
    if(!arg) {
	write("Li tells you: I can handle "+max_dir_entries+" files.\n");
	return 1;
    }
    else {
	max_dir_entries=(int)arg;
	write("Li tells you: Ok, I will try to handle "+
	  max_dir_entries+" files.\n");
	return 1;
    }
}

int lib_get_parameters(string str) {
    string *parameters;
    int i;

    parameters = explode(str, " ");
    write("number = "+sizeof(parameters)+"\n");
    for (i=0; i < sizeof(parameters); i++) {
	write(i+"'"+parameters[i]+"'\n");
    }
    return 1;
}

int lib_file_name() {
    string f1,tmp1,tmp2;

    if (sscanf(file_name(this_object()),"%s#%s",tmp1,tmp2)==2) {
	write("autoload = "+tmp1+"!\n");
    }
    write("creator = "+creator(this_object())+"\n");
    if (IS_ARCH) { write("is_arch\n"); }
    if (IS_WIZ)  { write("is_wiz\n"); }
    if (IS_NEW)  { write("is_new\n"); }
    if (IS_APPR) { write("is_appr\n"); }
    if (IS_ME)   { write("is_me\n"); }
    if (IS_OWNER) { write("is_owner\n"); }
    if (NO_OWNER) { write("no_owner\n"); }
    if (IS_PERM) { write("has permission to use\n"); }
    return 1;
}

/* returns 1 if file exists, 0 if not */
int lib_file_exists(string f1) {
    int s1;

    s1 = file_size(f1);
    return (s1 >= 0);
}

void lib_failed() {
    write("The librarian failed! Mail his boss please!\n");
    return;
}

string lib_fn_expand(string f1) {
    string tmp1,tmp2;
    string oldf1;

    oldf1 = f1;
    /* expand '~/' to '/players/' */
    if (sscanf(f1,"~/%s",tmp1) == 1)
	f1 = "/players/" + tmp1;
    /* expand '&/' to '/players/<wizname>/' */
    if (sscanf(f1,"&/%s",tmp1) == 1)
	f1 = "/players/"+TP->query_real_name()+"/"+tmp1;

    /* current dir if not starting from root */
    if(f1[0..0]!="/")
	f1 = "/"+this_player()->query_path()+"/"+f1;

    if ((f1 != oldf1) && (mode == 2))
	write("The librarian expands that to '"+f1+"'.\n");
    return f1;
}

string lib_fix_path(string arg) {
    string f1;
    int s1;

    f1=arg;
    /* check if its a dir */
    s1 = file_size(f1);
    if (s1==-2)
	f1+="/.";

    return f1;
}

int lib_copy_file(string f1,string f2) {
    string all;
    int s1,s2;
    string tmp1,tmp2,fname;
    string *chunk;

    if (!interactive(TP)) {
	destruct(TO);
	return 1;
    }
    /* get filename without path in 'fname' */
    fname = f1;
    while (sscanf(fname,"%s/%s",tmp1,tmp2)==2) {
	fname = tmp2;
    }
    f1 = lib_fn_expand(f1);
    s1 = file_size(f1);
    if (s1== -1) {
	write("The librarian tells you:'Sorry, I cannot copy "+f1+"'.\n");
	return 0;
    }
    f2 = lib_fn_expand(f2);
    chunk = explode(f2,"/");
    if (!IS_LORD) {
	if ((chunk[1] != "players") || (chunk[2] != TP->query_real_name())) {
	    write("The librarian tells you:'I am not allowed to write there!'\n");
	    return 0;
	}
    }
    s2 = file_size(f2);
    if (s2 == -2) {
	f2 = f2 + "/" + fname;
	if (mode == 2)
	    write("Destination is a dir, I will keep the filename the same :-)\n");
    }
    if (s2 >= 0) {
	write("The librarian tells you:'You already have that one!'\n");
	return 0;
    }
    if (mode == 2)
	write("You show your card to the librarian, he starts reading...\n");
    all=read_file(f1);
    if (mode == 2)
	write("After reading long pages he starts writing...\n");
    /* here some code to check if its the ownerdir */
    write_file(f2, all);
    if (mode == 2)
	write(".. in "+f2+"\n");
    if (!lib_file_exists(f2)) {
	lib_failed();
	return 0;
    }
    return 1;
}

/* multi file copy, not finished */
int lib_multi_copy_file(string f1,string f2) {
    string all;
    int s1,s2;
    string tmp1,tmp2,fname,path1,path2;
    string *chunk;
    string *tmp,*files;
    int i,j;

    if (!interactive(TP)) {
	destruct(TO);
	return 1;
    }
    /* get filename without path in 'fname' */
    fname = f1;
    while (sscanf(fname,"%s/%s",tmp1,tmp2)==2) {
	fname = tmp2;
    }
    f1 = lib_fn_expand(f1);
    f2 = lib_fn_expand(f2);

    /* check if write is permitted */
    chunk = explode(f2,"/");
    if ((!IS_LORD)&&((chunk[1]!="players")||(chunk[2]!=TP->query_real_name()))) {
	write("The librarian tells you:'I am not allowed to write there!'\n");
	return 0;
    }

    /* get sourcepath and destinationpath */
    s1 = file_size(f1);
    if (s1!=-2) {
	tmp=explode(f1, "/");
	tmp=del_array(tmp, sizeof(tmp)-1);
	path1=implode(tmp, "/");
    }
    else
	path1=f1;
    if(path1[-1..-1]!="/") path1+="/";
    s2 = file_size(f2);
    if (s2!=-2) {
	tmp=explode(f2, "/");
	tmp=del_array(tmp, sizeof(tmp)-1);
	path2=implode(tmp, "/");
    }
    else
	path2=f2;
    if(path2[-1..-1]!="/") path2+="/";

    /* now see if source is mutiple, single or empty (j) */
    files=get_dir(f1);
    if(!(j=sizeof(files))) {
	write("The librarian tells you:'Sorry, I cannot find "+f1+"'.\n");
	return 0;
    }

    /* if source is mutiple destination has to be a dir */
    if ((j>0)&&(s2!=-2)) {
	write("The librarian tells you:"
	  + "'If you use wildcards, destination has to be a dir!'\n");
	return 0;
    }

    if (j>1) {
	/* use multi-copy to another dir */
	int multi_ok;
	multi_ok=1;
	if (mode == 2)
	    write("Source is multifile, destination is a dir, I'll start now :-)\n");
	for(i=0;i<j;i++) {
	    string file;
	    if(files[i]!="." && files[i]!="..") {
		s1 = file_size(path1 + files[i]);
		if (s1 == -2) {
		    if (mode == 2)
			write("The librarian skips "+path2+files[i]+", its a dir.\n");
		}
		else {
		    s2 = file_size(path2 + files[i]);
		    if (s2 >= 0) {
			write("The librarian tells you:I will not overwrite "+path2+files[i]+"\n");
		    }
		    else {
			if (mode == 2)
			    write("Librarian reads "+path1+files[i]+"\n");
			file=read_file(path1 + files[i]);
			if (mode == 2)
			    write("Librarian writes "+path2+files[i]+"\n");
			write_file(path2+files[i], file);
			if (!lib_file_exists(path2+files[i])) {
			    multi_ok=0;
			}
		    }
		}
	    }
	}
	return multi_ok;
    } /* end multi-copy */
    /* use single-copy to another dir or to a copy in same dir */
    s2 = file_size(f2);
    if (s2 == -2) {
	f2 = f2 + "/" + fname;
	if (mode == 2)
	    write("Destination is a dir, I will keep the filename the same :-)\n");
    }
    if (s2 >= 0) {
	write("The librarian tells you:'You already have that one!'\n");
	return 0;
    }
    if (mode == 2)
	write("You show your card to the librarian, he starts reading...\n");
    all=read_file(f1);
    if (mode == 2)
	write("After reading long pages he starts writing...\n");
    /* here some code to check if its the ownerdir */
    write_file(f2, all);
    if (!lib_file_exists(f2))
	return 0;
    /* end single-copy */
    return 1;
}

int lib_move_file(string f1,string f2) {
    string all;
    int s1,s2;
    string tmp1,tmp2,fname;
    string *chunk;

    if (!interactive(TP)) {
	destruct(TO);
	return 1;
    }
    /* get filename without path in 'fname' */
    fname = f1;
    while (sscanf(fname,"%s/%s",tmp1,tmp2)==2) {
	fname = tmp2;
    }
    f1 = lib_fn_expand(f1);
    s1 = file_size(f1);
    if (s1== -1) {
	write("The librarian tells you:'Sorry, I cannot copy "+f1+"'.\n");
	return 0;
    }
    f2 = lib_fn_expand(f2);
    chunk = explode(f2,"/");
    if (!IS_LORD) {
	if ((chunk[1] != "players") || (chunk[2] != TP->query_real_name())) {
	    write("The librarian tells you:'I am not allowed to write there!'\n");
	    return 0;
	}
    }
    s2 = file_size(f2);
    if (s2 == -2) {
	f2 = f2 + "/" + fname;
	if (mode == 2)
	    write("Destination is a dir, I will keep the filename the same :-)\n");
    }
    if (s2 >= 0) {
	write("The librarian tells you:'You already have that one!'\n");
	return 0;
    }
    if (mode == 2)
	write("You show your card to the librarian, he takes "+f1+"...\n");
    /*  if (!command("mv "+f1+" "+f2,this_player())) { */
    if (!this_player()->movefile(f1+" "+f2)) {
	write("but he drops it before he can take a step!\n");
	return 0;
    }
    if (mode == 2)
	write("and moves it to "+f2+".\n");
    return 1;
}

/* show dir of path */
int lib_dir(string str) {
    string path;
    int max, i, len, tmp;
    status trunc_flag;
    string *dir;
    string *rawfile,*parm;

    if (!interactive(TP)) {
	destruct(TO);
	return 1;
    }
    path=str;
    dir = get_dir (path);
    if (!dir) {
	write("The librarian tells you:'I cant find that path, sorry!'\n");
	return 1;
    }
    if (sizeof(dir) > max_dir_entries+1)
    {
	dir = dir[0..max_dir_entries];
	trunc_flag = 1;
    }
    for (i=0; i < sizeof(dir); i++) {
	/* check for ' ' in filename */
	rawfile = explode(dir[i], " ");
	if (rawfile[0] != dir[i]) {
	    dir[i]+="?";
	} else
	    /* check if its a directory */
	if (file_size(path + "/" + dir[i]) == -2)
	    dir[i]+="/";
	/* check if its loaded */
	parm = explode(path, ".");
	rawfile = explode(dir[i], ".");
	if (find_object(parm[0]+rawfile[0])) {
	    dir[i] += "*";
	}
	len = strlen(dir[i]);
	if (len >= max)
	    max = len+1;
    }
    if (max > 79)
	max = 79;
    write("The librarian shows the list of "+path+"'\n");
    for (i=0; i < sizeof(dir); i++) {
	string name;
	name = dir[i];
	tmp = strlen(name);
	if (len + tmp > 79) {
	    len = 0;
	    write("\n");
	}
	write(name);
	if (len + max > 80) {
	    write("\n");
	    len = 0;
	} else {
	    write(extract(
		"                                                                                ",
		80-max+tmp));
	    len += max;
	}
    }
    write("\n");
    if (trunc_flag) write("***TRUNCATED***\n");
    return 1;
}

/* show numbered dir of path */
int lib_numbered_dir(string str,int start,int end) {
    string path,*parm;
    int max, i, len, tmp;
    status trunc_flag;
    string *dir;
    string *rawfile;
    int low,high;

    if (!interactive(TP)) {
	destruct(TO);
	return 1;
    }
    low=(start-1);
    high=(end-1);
    path=str;
    dir = get_dir (path);
    if (!dir) {
	write("The librarian tells you:'I cant find that path, sorry!'\n");
	return 1;
    }
    /* check if interval too big */
    if ((int)high>=sizeof(dir))
	high=sizeof(dir);
    if (((int)high-(int)low)>max_dir_entries-1) {
	trunc_flag = 1;
	high=low+max_dir_entries-1;
    }
    dir = dir[(int)low..(int)high];
    for (i=0; i < sizeof(dir); i++) {
	/* check for ' ' in filename */
	rawfile = explode(dir[i], " ");
	if (rawfile[0] != dir[i]) {
	    dir[i]+="?";
	} else
	    /* check if its a directory */
	if (file_size(path + "/" + dir[i]) == -2)
	    dir[i]+="/";
	/* check if its loaded */
	parm = explode(path, ".");
	rawfile = explode(dir[i], ".");
	if (find_object(parm[0]+rawfile[0])) {
	    dir[i] += "*";
	}
	len = strlen(dir[i]);
	if (len >= max)
	    max = len+1;
    }
    if (max > 79)
	max = 79;
    write("The librarian shows the files "+(low+1)+ " to " + (high+1)+ 
      " of "+path+"'\n");
    for (i=0; i < sizeof(dir); i++) {
	string name;
	name = dir[i];
	tmp = strlen(name);
	if (len + tmp > 79) {
	    len = 0;
	    write("\n");
	}
	write(name);
	if (len + max > 80) {
	    write("\n");
	    len = 0;
	} else {
	    write(extract(
		"                                                                                ",
		80-max+tmp));
	    len += max;
	}
    }
    write("\n");
    if (trunc_flag) write("***TRUNCATED***\n");
    return 1;
}

int do_lib_help(string arg)  {
    string *man;
    int size_man,i;

    man=({ 
      "fc",
      "file1, file2",
      "Compare two files. Li will tell you if the files are the same or if "+
      "they are different.",
      "lstr",
      "string, files",
      "Search string in files. Li will search all specified files for the "+
      "string and show you the lines that contain the string. "+
      "\nNEW features: Li now can search strings that contain spaces. "+
      "Type 'lstr void@reset *' and Li will search for 'void reset' in all "+
      "files. Also Li will now display the number of occurences and the "+
      "number of files that contains the string. ",
      "repstr",
      "oldstr, newstr, files",
      "Replace string in files. Li will search in all specified files for "+
      "oldstr and then replace it with the newstr. This command is very "+
      "powerful, and mistakes can be hard to correct so use it wisely. "+
      "If you have any doubts then rather use 'frepstr'.",
      "frepstr",
      "oldstr, newstr, files",
      "NEW TRICK! Replace string in files. "+
      "This command works the same as 'repstr' but it also appends the old "+
      "lines to /players/"+TP->query_real_name()+"/frepstr.log as a backup "+
      "in case of calamities or just to have a list of changes.",
      "lcp",
      "file1, file2||dir",
      "This will copy file1 to file2 or to a dir. It was put in the librarian "+
      "in a time that the 'cp' command was not yet available in this world. "+
      "The only advantage right now is that it supports the built in filename "+
      "expander.",
      "mcp",
      "files, dir",
      "multicopy files to a dir. The specified files will be copied to the dir. "+
      "It supports the built in filename expander and also wildcards can be "+
      "used.",
      "lmv",
      "file1, file2||dir",
      "This will move file1 to file2 or to a dir. It was put in the librarian "+
      "in a time that the 'mv' command was not yet available in this world. "+
      "The only advantage right now is that it supports the built in filename "+
      "expander.",
      "cleardir",
      "you'll find out",
      "This will remove all files in current dir. Think three times before "+
      "using it, you have been warned ;-)",
      "ltree",
      "[dir]",
      "Li will draw a tree of the dir and all its subdirs. This costs a load "+
      "of cycles, so find out if you really need it.",
      "ldir",
      "[dir]",
      "The librarian shows a dir listing with extra info. '*' is appended "+
      "to loaded files, '/' is appended to dirs and '?' is appended to "+
      "invalid filenames."+
      "It supports the built in filename expander.",
      "fdir",
      "dirpath, filepath",
      "This works like the 'ldir' but the listing is written to a file.",
      "ddir",
      " ",
      "Deep dir, the librarian will show the contents of the dir and all its "+
      "subdirs. This draws heavily from the cpu, don't use unless you know "+
      "why you do it ;-). A nice feature of it is that you can locate files "+
      "with it by specifying the name or using wildcards.",
      "libmode",
      "debug||nodebug",
      "Change mode of librarian. If you choose debug he will give you loads "+
      "of extra information while he works, if you choose nodebug he will "+
      "be a bit more quiet.",
      "lhelp",
      " ",
      "Hmm, you should try this one to see what it does..."
    });
    size_man=sizeof(man);
    if(arg) {
	i=member_array(arg,man);
	if((i!=-1)&&(i+2<size_man))
	    printf("%-10=s- %-*=s\n\n",man[i],SCREEN_WIDTH-12,"arguments: "+
	      man[i+1]+"\n"+man[i+2]);
	return 1;
    }
    write("Li tells you all about his tricks:\n");
    for(i-0;i<size_man;i+=3) {
	printf("%-10=s- %-*=s\n\n",man[i],SCREEN_WIDTH-12,"arguments: "+
	  man[i+1]+"\n"+man[i+2]);
    }
    write("\n"
      +"built in filename-expander:\n"
      +"- If you dont specify path, I 'll add current path.\n"
      +"- I will replace '~/' with '/players/'.\n"
      +"- I will replace '&/' with '/players/"+TP->query_real_name()+"/'.\n"
      +"\n"
      +"...well thats it for today, but I keep learning!\n"
      +"If I do not function properly, please warn my boss :-)\n");
    /* no longer needed ...
      if (NO_OWNER) {
	write("WARNING: Some file functions that do writing or deleting require\n"+
	      "that you are the owner of this tool. If you need these functions\n"+
	      "copy /tools/filetool.c to one of your own dirs, destruct this\n"+
	      "tool and clone the tool from your own dir.\n"+
	      "The autoload will automatic choose your own copy next time.\n");
      }
    */
    /*  if (IS_ME) {
	write(""
      +"testname                 - does tool decide wiztype correct?\n"
      +"testpar                  - do parameters work correct?\n"
      );
      }*/
    return 1;
}

int do_copy(string str) {
    string f1,f2;
    int s1,s2;
    string tmp1,tmp2,fname;
    string *parm;
    int i;

    if (!interactive(TP)) {
	destruct(TO);
	return 1;
    }
    parm = explode(str, " ");
    if (sizeof(parm) != 2) {
	write("The librarian gasps in astonishment, but doesnt understand!\n");
	return 1;
    }
    if (lib_copy_file(parm[0],parm[1])) {
	if (mode == 1)
	    write("The librarian tells you: Done.\n");
	if (mode == 2)
	    write("He drops his feather after a while and sighs: finished!\n");
    }
    return 1;
}

int do_multi_copy(string str) {
    string f1,f2;
    int s1,s2;
    string tmp1,tmp2,fname;
    string *parm;
    int i;

    if (!interactive(TP)) {
	destruct(TO);
	return 1;
    }
    parm = explode(str, " ");
    if (sizeof(parm) != 2) {
	write("The librarian gasps in astonishment, but doesnt understand!\n");
	return 1;
    }
    if (lib_multi_copy_file(parm[0],parm[1])) {
	if (mode == 1)
	    write("The librarian tells you: Done.\n");
	if (mode == 2)
	    write("He drops his feather after a while and sighs: finished!\n");
    }
    else
	lib_failed();
    return 1;
}

int do_move(string str) {
    string f1,f2;
    int s1,s2;
    string tmp1,tmp2,fname;
    string *parm;
    int i;

    if (!interactive(TP)) {
	destruct(TO);
	return 1;
    }
    parm = explode(str, " ");
    if (sizeof(parm) != 2) {
	write("The librarian gasps in astonishment, but doesnt understand!\n");
	return 1;
    }
    if (lib_move_file(parm[0],parm[1])) {
	if (mode == 1)
	    write("The librarian tells you: Done.\n");
    }
    return 1;
}

int do_old_move(string str) {
    string f1,f2;

    if (!interactive(TP)) {
	destruct(TO);
	return 1;
    }
    if (sscanf(str, "%s to %s", f1, f2) != 2) {
	write("The librarian gasps in astonishment, but doesnt understand!\n");
	return 1;
    }
    write("You show your card to the librarian, he takes "+f1+"...\n");
    /* rename() is not implemented on Holy Mission! */
    /* do_move disabled, this tool uses do_temp_move() now */
    if (!rename(f1, f2)) {
	write("but he drops it before he can take a step!\n");
	return 1;
    }
    write("and moves it to "+f2+". finished!\n");
    return 1;
}

int do_temp_move(string str) {
    string f1,f2,all;
    string *parm;
    int i;

    if (!interactive(TP)) {
	destruct(TO);
	return 1;
    }
    parm = explode(str, " ");
    if (sizeof(parm) != 2) {
	write("The librarian gasps in astonishment, but doesnt understand!\n");
	return 1;
    }
    if (!lib_copy_file(parm[0],parm[1])) {
	return 1;
    }
    if (mode == 2)
	write("He drops his feather after a while and sighs: finished!\n");
    f1 = lib_fn_expand(parm[0]);
    if (!rm(f1)) {
	write("The librarian tries to tear "+f1+" apart but fails!\n");
	return 1;
    }
    if (mode == 1)
	write("The librarian tells you: Done.\n");
    if (mode == 2)
	write("The librarian tears "+f1+" to little shreds!\n");
    return 1;
}

int do_file_compare(string str) {
    string f1,f2;
    int s1,s2;
    string all1,all2;
    string *parm;
    int i;

    if (!interactive(TP)) {
	destruct(TO);
	return 1;
    }
    parm = explode(str, " ");
    if (sizeof(parm) != 2) {
	write("The librarian gasps in astonishment, but doesnt understand!\n");
	return 1;
    }
    f1 = lib_fn_expand(parm[0]);
    s1 = file_size(f1);
    if (s1 <= 0) {
	write("The librarian tells you:'Sorry, "+f1+" is not a file!\n");
	return 1;
    }
    f2 = lib_fn_expand(parm[1]);
    s2 = file_size(f2);
    if (s2 <= 0) {
	write("The librarian tells you:'Sorry, "+f2+" is not a file!\n");
	return 1;
    }
    all1 = read_file(f1);
    all2 = read_file(f2);
    if (all1 == all2) {
	write("The librarian tells you:'They are the same!'\n");
	return 1;
    }
    write("The librarian tells you:'They are different!'\n");
    return 1;
}

int do_dir(string str) {
    string *parm;
    string path;

    if (!interactive(TP)) {
	destruct(TO);
	return 1;
    }
    if (!str) {
	str = "/"+this_player()->query_path();
    }
    parm = explode(str, " ");
    if (sizeof(parm) > 1) {
	write("The librarian gasps in astonishment, but doesnt understand!\n");
	return 1;
    }
    path = parm[0];
    path = lib_fn_expand(path);
    /* yyy  if (path != "/")
	path = path + "/."; */
    path=lib_fix_path(path);
    lib_dir(path);
    return 1;
}

int do_numbered_dir(string str) {
    string path;
    int parms,low,high;
    string *tmp;

    if (!interactive(TP)) {
	destruct(TO);
	return 1;
    }
    if (!str) {
	str = "/"+this_player()->query_path();
    }
    if(sscanf(str,"%s %d %d",path,low,high)!=3) {
	tmp=explode(str," ");
	if(sizeof(tmp)>1) {
	    write("The librarian gasps in astonishment, but doesnt understand!\n");
	    write("The librarian says: ndir path lownumber highnumber!\n");
	    return 1;
	}
	path=str;
	low=1;
	high=max_dir_entries;
    } 
    path = lib_fn_expand(path);
    path=lib_fix_path(path);
    lib_numbered_dir(path,low,high);
    return 1;
}

int do_ls(string str) {
    int max, i, len, tmp;
    status trunc_flag;
    string *dir;
    string path;
    string *parm,*rawfile;

    if (!interactive(TP)) {
	destruct(TO);
	return 1;
    }
    if (!str) {
	str = "/"+this_player()->query_path();
    }
    parm = explode(str, " ");
    if (sizeof(parm) > 1) {
	write("The librarian gasps in astonishment, but doesnt understand!\n");
	return 1;
    }
    path = parm[0];
    path = lib_fn_expand(path);
    /* yyy  if (path != "/")
	path = path + "/.";*/
    dir = get_dir (path);
    if (!dir) {
	write("The librarian tells you:'I cant find that path, sorry!'\n");
	return 1;
    }
    if (sizeof(dir) > max_dir_entries+1)
    {
	dir = dir[0..max_dir_entries];
	trunc_flag = 1;
    }
    for (i=0; i < sizeof(dir); i++) {
	/* check for ' ' in filename */
	rawfile = explode(dir[i], " ");
	if (rawfile[0] != dir[i]) {
	    dir[i]+="?";
	} else
	    /* check if its a directory */
	if (file_size(path + "/" + dir[i]) == -2)
	    dir[i]+="/";
	/* check if its loaded */
	parm = explode(path, ".");
	rawfile = explode(dir[i], ".");
	if (find_object(parm[0]+rawfile[0])) {
	    dir[i] += "*";
	}
	len = strlen(dir[i]);
	if (len >= max)
	    max = len+1;
    }
    if (max > 79)
	max = 79;
    write("The librarian tells you:'Here is the list of "+path+"'\n");
    for (i=0; i < sizeof(dir); i++) {
	string name;
	name = dir[i];
	tmp = strlen(name);
	if (len + tmp > 79) {
	    len = 0;
	    write("\n");
	}
	write(name);
	if (len + max > 80) {
	    write("\n");
	    len = 0;
	} else {
	    write(extract(
		"                                                                                ",
		80-max+tmp));
	    len += max;
	}
    }
    write("\n");
    if (trunc_flag) write("***TRUNCATED***\n");
    return 1;
}

int do_ls_to_file(string str) {
    int max, i, len, tmp;
    status trunc_flag;
    string *dir;
    string path;
    string *parm,*rawfile;
    string fn;

    if (!interactive(TP)) {
	destruct(TO);
	return 1;
    }
    if (!str) {
	str = "/"+this_player()->query_path();
    }
    parm = explode(str, " ");
    if (sizeof(parm) > 2) {
	write("The librarian gasps in astonishment, but doesnt understand!\n");
	return 1;
    }
    fn = parm[1];
    path = parm[0];
    path = lib_fn_expand(path);
    /* yyy  if (path != "/")
	path = path + "/."; */
    path=lib_fix_path(path);
    dir = get_dir (path);
    if (!dir) {
	write("The librarian tells you:'I cant find that path, sorry!'\n");
	return 1;
    }
    if (sizeof(dir) > max_dir_entries+1)
    {
	dir = dir[0..max_dir_entries];
	trunc_flag = 1;
    }
    for (i=0; i < sizeof(dir); i++) {
	/* check for ' ' in filename */
	rawfile = explode(dir[i], " ");
	if (rawfile[0] != dir[i]) {
	    dir[i]+="?";
	} else
	    /* check if its a directory */
	if (file_size(path + "/" + dir[i]) == -2)
	    dir[i]+="/";
	/* check if its loaded */
	parm = explode(path, ".");
	rawfile = explode(dir[i], ".");
	if (find_object(parm[0]+rawfile[0])) {
	    dir[i] += "*";
	}
	len = strlen(dir[i]);
	if (len >= max)
	    max = len+1;
    }
    if (max > 79)
	max = 79;
    write("The librarian tells you:'Here is the list of "+path+"'\n");
    for (i=0; i < sizeof(dir); i++) {
	string name;
	name = dir[i];
	tmp = strlen(name);
	if (len + tmp > 79) {
	    len = 0;
	    write_file(fn, "\n");
	}
	write_file(fn, name);
	if (len + max > 80) {
	    write_file(fn, "\n");
	    len = 0;
	} else {
	    write_file(fn, extract(
		"                                                                                ",
		80-max+tmp));
	    len += max;
	}
    }
    write_file(fn, "\n");
    if (trunc_flag) write_file(fn, "***TRUNCATED***\n");
    if (!lib_file_exists(fn)) {
	lib_failed();
    }
    return 1;
}

/* show dir and do recursion for subdirs */
/* called from do_deep_dir()             */
int deep_dir_branch(string tmppath,string files) {
    int i, br;
    status trunc_flag;
    string *dir;
    string next_branch,path;

    if (!interactive(TP)) {
	destruct(TO);
	return 1;
    }
    path=tmppath;
    /* DEBUG write("Librarian looks at shelf "+tree_level+".\n");*/
    /* DEBUG write("looking for "+files+" in "+path+"\n");*/
    lib_dir(path+"/"+files);
    dir = get_dir (path+"/.");
    if (!dir) {
	write("The librarian tells you:'I cant find that path, sorry!'\n");
	return 1;
    }
    if (sizeof(dir) > max_dir_entries+1)
    {
	dir = dir[0..max_dir_entries];
	trunc_flag = 1;
    }
    tree_level++;
    for (i=0; i < sizeof(dir); i++) {
	/* check if its a directory */
	if (file_size(path + "/" + dir[i]) == -2) {
	    /* DEBUG      write(dir[i]+"\n");*/
	    next_branch = path + "/" + dir[i];
	    br = deep_dir_branch(next_branch,files);
	}
    }
    tree_level--;
    return 1;
}

/* show dir and all subdirs recursively */
/* calls deep_dir_branch()              */
int do_deep_dir(string str) {
    int br;
    string path,files;
    string *parm;

    if (!interactive(TP)) {
	destruct(TO);
	return 1;
    }
    if (!str) {
	str = "/"+this_player()->query_path();
    }
    parm = explode(str, " ");
    if (sizeof(parm) > 1) {
	write("The librarian gasps in astonishment, but doesnt understand!\n");
	return 1;
    }
    path = lib_fn_expand(str);
    /* DEBUG  write(path + "\n"); */
    tree_level = 0;
    path = lib_fix_path(path); /* all files if no filespec */

    /* split in path and files */
    parm = explode(path, "/");
    files=parm[sizeof(parm)-1];
    parm=del_array(parm,sizeof(parm)-1);
    path=implode(parm,"/");

    br = deep_dir_branch(path,files);
    return 1;
}

int dir_tree_branch(string str) {
    int i, j, br;
    status trunc_flag;
    string *dir;
    string path;
    string next_branch;

    if (!interactive(TP)) {
	destruct(TO);
	return 1;
    }
    path=lib_fix_path(str);
    /* yyy  if (path != "/")
	path = path + "/.";*/
    dir = get_dir (path);
    if (!dir) {
	write("The librarian tells you:'I cant find that path, sorry!'\n");
	return 1;
    }
    if (sizeof(dir) > max_dir_entries+1)
    {
	dir = dir[0..max_dir_entries];
	trunc_flag = 1;
    }
    tree_level++;
    for (i=0; i < sizeof(dir); i++) {
	/* check if its a directory */
	if (file_size(str + "/" + dir[i]) == -2) {
	    for (j=0; j < tree_level; j++) {
		write("    ");
	    }
	    write(dir[i]+"\n");
	    next_branch = str + "/" + dir[i];
	    br = dir_tree_branch(next_branch);
	}
    }
    tree_level--;
    return 1;
}

int do_dir_tree(string str) {
    int br;
    string path;
    string *parm;

    if (!interactive(TP)) {
	destruct(TO);
	return 1;
    }
    if (!str) {
	str = "/"+this_player()->query_path();
    }
    parm = explode(str, " ");
    if (sizeof(parm) > 1) {
	write("The librarian gasps in astonishment, but doesnt understand!\n");
	return 1;
    }
    path = parm[0];
    path = lib_fn_expand(path);
    write(path + "\n");
    tree_level = 0;
    br = dir_tree_branch(path);
    return 1;
}

int do_list(string str) {
    int max, i, len, tmp, br;
    status trunc_flag;
    string *dir;
    string path;
    string *parm,*rawfile;
    string fn;
    string tmppath;
    string next_branch;

    if (!interactive(TP)) {
	destruct(TO);
	return 1;
    }
    if (!str) {
	str = "/"+this_player()->query_path();
    }
    parm = explode(str, " ");
    if (sizeof(parm) > 2) {
	write("The librarian gasps in astonishment, but doesnt understand!\n");
	return 1;
    }
    path = parm[0];
    path = lib_fn_expand(path);
    tmppath = path;
    /* yyy  if (path != "/")
	path = path + "/.";*/
    dir = get_dir (path);
    if (!dir) {
	write("The librarian tells you:'I cant find that path, sorry!'\n");
	return 1;
    }
    if (sizeof(dir) > max_dir_entries+1)
    {
	dir = dir[0..max_dir_entries];
	trunc_flag = 1;
    }
    for (i=0; i < sizeof(dir); i++) {
	/* check if its a directory */
	if (file_size(tmppath + "/" + dir[i]) == -2) {
	    write(tmppath + "/" + dir[i]+"\n");
	    next_branch = tmppath + "/" + dir[i];
	    br = do_list(next_branch);
	}
    }
    return 1;
}

int do_remove_file(string str) {
    int max, i, len, tmp;
    status trunc_flag;
    string *dir,*chunk;
    string path;
    string f1;
    string tmp1;

    if (!interactive(TP)) {
	destruct(TO);
	return 1;
    }
    path = "/"+this_player()->query_path()+"/.";
    if (str != "please") {
	write("The librarian tells you:'Well, that is a dangerous command!\n"
	  +"All books in '"+path+"' would be destroyed!\n"
	  +"But I will do it for you, if you add 'please'...\n");
	return 1;
    }
    chunk = explode(path,"/");
    if (!IS_LORD) {
	if ((chunk[1] != "players") || (chunk[2] != TP->query_real_name())) {
	    write("The librarian tells you:'I am not allowed to write there!'\n");
	    return 1;
	}
    }
    dir = get_dir (path);
    if (!dir) {
	write("The librarian cannot find that directory\n");
	return 1;
    }
    if (sizeof(dir) == 0) {
	write("The librarian tells you: But it is already clean!\n");
	return 1;
    }
    if (sizeof(dir) > max_dir_entries+1)
    {
	dir = dir[0..max_dir_entries];
	trunc_flag = 1;
    }
    for (i=0; i < sizeof(dir); i++) {
	f1 = lib_fn_expand(dir[i]);
	if (!rm(f1)) {
	    /* tryout
		if (sscanf(f1,"/%s",tmp1)==1) { f1 = tmp1; }
		if (!this_player()->remove_file(f1)) {
	    */
	    write("The librarian tries to tear "+dir[i]+" apart but fails!\n");
	}
	else {
	    if (mode == 2)
		write("The librarian tears "+dir[i]+" to little shreds!\n");
	}
    }
    dir = get_dir (path);
    write(sizeof(dir)+" files left :*)\n");
    if (sizeof(dir) != 0) {
	lib_failed();
	return 1;
    }
    if (mode == 1)
	write("The librarian tells you: Done.\n");
    return 1;
}

int do_send (string str) {
    object this_ob, player;
    int result;

    if (!interactive(TP)) {
	destruct(TO);
	return 1;
    }
    if (!str) return 1;
    player=find_living(str);
    if (!player) return 1;
    if (!player->query_immortal()) {
	write("The librarian tells you:'I dont want to go to a player!'\n");
	return 1;
    }
    result=(transfer(clone_object(FILE),player));
    if (result != 0) {
	write("The librarian tells you:'I couldnt go! errornr "+result+"'\n");
	return 1;
    }
    tell_object(player,capitalize(TP->query_real_name()) +
      " sent you '"+this_object()->short()+"'\n");
    write("You sent "+this_object()->short()+" to "+capitalize(str)+"\n");
    return 1;
}

int do_update (string str) {
    object this_ob, player;
    int result;

    if (!interactive(TP)) {
	destruct(TO);
	return 1;
    }
    if (!str) return 1;
    player=find_living(str);
    if (!player) return 1;
    if (!player->query_immortal()&&TP->query_real_name()!="celeborn") {
	write("The librarian tells you:'I dont want to go to a player!'\n");
	return 1;
    }
    result=(transfer(clone_object(FILE),player));
    if (result != 0) {
	write("The librarian tells you:'I couldnt go! errornr "+result+"'\n");
	return 1;
    }
    write("You sent "+this_object()->short()+" to "+capitalize(str)+"\n");
    return 1;
}

int do_set_mode(string str) {
    if (!interactive(TP)) {
	destruct(TO);
	return 1;
    }
    if (!str) {
	write("The librarian tells you:'I have <debug> and <nodebug>.'\n");
	return 1;
    }
    if (str == "debug") {
	mode = 2;
	write("ok, I 'll tell you all I know *sigh*\n");
	return 1;
    }
    if (str == "nodebug") {
	mode = 1;
	write("ok, I know when I talk too much *sigh*\n");
	return 1;
    }
    write("the librarian tells you:'Sorry, I don't know that mode!'\n");
    return 1;
}

string lib_fix_spaces(string str) {
    string *tmp1,*tmp2;
    string oldstr,spacechar,double_spacechar;
    int i;

    spacechar="@";
    double_spacechar=spacechar+spacechar;
    oldstr = str;

    /* change @ to spaces, change @@ to @ */
    tmp1=explode(str,double_spacechar);
    for(i=0;i<sizeof(tmp1);i++) {
	tmp2=explode(tmp1[i],spacechar);
	tmp1[i]=implode(tmp2," ");
    }
    str=implode(tmp1,spacechar);

    if ((str != oldstr) && (mode == 2))
	write("The librarian expands '"+oldstr+"' to '"+str+"'.\n");
    return str;
}

/* original tool: grep programmed by Moonchild */
/* 300793: Galadriel: added lines in which expression appears */
/* 310793: Galadriel: added linenumbers also */
/* ??0993: Galadriel: added save in resultline and writing to file */
/* 310894: Galadriel: added handling of @ and @@ (lib_fix_spaces) */

status do_search_str(string str) {
    string exp,dir,pathname,result,*tmp,*files,*lines;
    int i,j,k,nr,nrf;

    if (!interactive(TP)) {
	destruct(TO);
	return 1;
    }
    if(!str) return 0;
    if(sscanf(str, "%s %s", exp, dir)!=2) {
	write("Invalid syntax.\n");
	return 1;
    }
    exp=lib_fix_spaces(exp);
    nr=0;
    nrf=0;
    if(dir[0..0]!="/")
	dir="/" + (string)this_player()->query_path() + "/" + dir;
    tmp=explode(dir, "/");
    tmp=del_array(tmp, sizeof(tmp)-1);
    pathname=implode(tmp, "/");
    if(pathname[-1..-1]!="/") pathname+="/";
    files=get_dir(dir);
    if(!(j=sizeof(files))) {
	write("No files.\n");
	return 1;
    }
    for(i=0;i<j;i++) {
	string file;
	if(files[i]!="." && files[i]!="..") {
	    file=read_file(pathname + files[i]);
	    if(file && sizeof(explode(file, exp)) > 1) {
		result=("Found " + exp + " in: " + pathname + files[i] + "\n");
		if(!logmode)
		    write(result);
		else
		    write_file(logfile,result);
		lines=explode(file,"\n");
		for(k=0;k<sizeof(lines);k++)
		    if(sizeof(explode(lines[k], exp)) > 1) {
			result=sprintf(k+1+":"+lines[k]+"\n");
			if(!logmode)
			    write(result);
			else
			    write_file(logfile,result);
			nr++;
		    }
		nrf++;
	    }
	}
    }
    result="Li tells you: I found "+nr+" occurrences in "+nrf+" files.\n";
    if(!logmode)
	write(result);
    else
	write_file(logfile,result);
    return 1;
}

status do_replace_str(string str) {
    string exp,newexp,dir,result,pathname,*tmp,*files,*lines;
    int i,j,k,nr,nrf;

    if (!interactive(TP)) {
	destruct(TO);
	return 1;
    }
    if(!str) return 0;
    if(sscanf(str, "%s %s %s", exp, newexp, dir)!=3) {
	write("Invalid syntax.\n");
	return 1;
    }
    exp=lib_fix_spaces(exp);
    newexp=lib_fix_spaces(newexp);
    nr=0;
    nrf=0;
    if(dir[0..0]!="/")
	dir="/" + (string)this_player()->query_path() + "/" + dir;
    tmp=explode(dir, "/");
    tmp=del_array(tmp, sizeof(tmp)-1);
    pathname=implode(tmp, "/");
    if(pathname[-1..-1]!="/") pathname+="/";
    files=get_dir(dir);
    if(!(j=sizeof(files))) {
	write("No files.\n");
	return 1;
    }
    if(logmode) {
	write_file(logfile,"'"+exp+"' ==> '"+newexp+"'\n");
	do_search_str(exp+" "+dir); /* save old lines to logfile */
    }
    write("Will change '" + exp + "' to '" + newexp + "'.\n");
    for(i=0;i<j;i++) {
	string file;
	if(files[i]!="." && files[i]!=".."
	  &&  file=read_file(pathname + files[i])) {
	    lines=explode(file, exp);
	    if(file && sizeof(lines) > 1) {
		write("Replacing " + exp + " in: " + pathname + files[i] + "\n");
		file=implode(lines, newexp);
		if (!rm(pathname + files[i])) {
		    write("The librarian tries to tear "+files[i]+" apart but fails!\n");
		}
		write_file(pathname + files[i], file);
		nrf++;
	    }
	}
    }
    result="Li tells you: I found and replaced "+nrf+" occurrences.\n";
    if(!logmode)
	write(result);
    else
	write_file(logfile,result);
    return 1;
}

status do_log_and_replace_str(string str) {
    logfile="/players/"+TP->query_real_name()+"/frepstr.log";
    logmode=1;
    do_replace_str(str);
    logmode=0;
    write("old lines added to "+logfile+"\n");
    return 1;
}
