/* DOCUMENT.C, Programmed by Ethereal Cashimor */
/* 270593: Updated the list function */
/* 020693: Checks build in */
/* 220693: More added to the documenter */
// Portil: 290994: Updated the scroll so that it now works with any length files

inherit "obj/thing";
#include "/obj/lw.h"
#define NOTIFY say(this_player()->query_name()+" reads a scroll.\n");

string functions,texts,filename,list;
int j,filesize;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("scroll");
    set_short("A scroll of documentation");
    set_long(lw("This scroll has the ability to provide docs on LPC files. "
              + "Read it for more information.\n"));
    set_value(100);
    set_can_get(1);
  }
}

init() {
  ::init();
  add_action("list_it","list");
}

read(str) {
int result;

  if(!str) {
    notify_fail("Read what?\n");
    return 0;
  }
  if(str=="scroll") {
    NOTIFY
    write(lw("This is a scroll of documentation. You can check out a file to "
           + "see what user functions are defined inside and how you can use "
           + "them. Possible commands of this scroll are: 'list "
           + "<filename>|again' and 'read <function>|scroll'. Before using "
           + "read you have to use list. Examples of using list: 'list "
           + "/obj/alco_drink.c' lists all userfunctions in "
           + "/obj/alco_drink.c. 'list again' lists these functions again. "
           + "Example of using read: 'read general' reads the general "
           + "explanation of the last listed file. 'read set_strength' reads "
           + "the documentation of the function set_strength in the last "
           + "listed file. 'read scroll' displays this text. Hope you enjoy "
           + "this scroll!\n"));
    return 1;
  }
  if(!functions) {
    notify_fail("List has to be executed before read!\n");
    return 0;
  }
  result=member_array(str,functions);
  if(result==-1) {
    notify_fail("Unknown function.\n");
    return 0;
  }
  NOTIFY
  write("Documentation of "+str+":\n");
  write(texts[result]);
  return 1;
}

list_it(str) {
string text,file;
int i;

  if(!str) {
    notify_fail("List what?\n");
    return 0;
  }
  if(str=="again") {
    if(!filename) {
      notify_fail("No file listed yet!\n");
      return 0;
    }
    write("List of user functions in "+filename+":\n");
    list="";
    for(i=0;i<sizeof(functions);i++) list+=functions[i]+"\n";
    if(list=="") list="None.";
    NOTIFY
    this_player()->more_string(sprintf("%-*#s\n",SCREEN_WIDTH,list));
    return 1;
  }
  filename=str;
  text=explode(filename,".");
  if(text[sizeof(text)-1]!="c") filename+=".c";
  file=read_bytes(filename,0,20);
  if(!file) {
    notify_fail("Unknown file!\n");
    return 0;
  }
  filesize=file_size(filename);
  j=0;
  functions=({});
  texts=({});
  list="";
  if(filesize>16000) write("Please wait about "+filesize/8000+" seconds whilst the list is calculated.\n"); 
  next_call_out();
  return 1;
}

query_auto_load() {
  return "players/portil/obj/document:";
}

drop() {
  return 1;
}

next_call_out() {
	int i,k,exfilesize;
	string exfile,file,function,text;

     k=j;
     while(k+16000>j && j<filesize) {
	file=read_bytes(filename,j,2000);
	j+=2000;
        exfile=explode(file,"\n");
	exfilesize=sizeof(exfile); // Its a bit quicker.....
        for(i=0;i<exfilesize;i++) {
          if(exfile[i]=="/* USERDOC:") {
          i++;
	  if(i==exfilesize) {
	      i=0;
	      file=read_bytes(filename,j,2000);
	      j+=2000;
              exfile=explode(file,"\n");
	      exfilesize=sizeof(exfile);
	  }
          function=exfile[i++];
          text="";
          functions+=({function});
          list+=function+"\n";
	  if(i==exfilesize) {
	      i=0;
	      file=read_bytes(filename,j,2000);
	      j+=2000;
              exfile=explode(file,"\n");
	      exfilesize=sizeof(exfile);
	  }
          while(exfile[i]!="*/") {
	    text+=exfile[i++]+"\n"; 
	    if(i==exfilesize) {
	      i=0;
	      file=read_bytes(filename,j,2000);
	      j+=2000;
              exfile=explode(file,"\n");
	      exfilesize=sizeof(exfile);
	    }
	  }
          texts+=({text});
        }
     }
  }
  if(j<filesize) call_out("next_call_out",2);
    else {
      if(list=="") list="None.";
      NOTIFY
      write("List of user functions in "+filename+":\n");
      this_player()->more_string(sprintf("%-*#s\n",SCREEN_WIDTH,list));
    }

}
