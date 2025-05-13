/* DOCUMENT.C, Programmed by Ethereal Cashimor */
/* 270593: Updated the list function */
/* 020693: Checks build in */
/* 220693: More added to the documenter */

inherit "obj/thing";
#include "/obj/lw.h"
#define NOTIFY say(this_player()->query_name()+" reads a scroll.\n");

string functions,texts,filename;

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
string file,exfile,function,text,list;
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
  file=read_file(filename);
  if(!file) {
    notify_fail("Unknown file!\n");
    return 0;
  }
  functions=({});
  texts=({});
  list="";
  exfile=explode(file,"\n");
  write("List of user functions in "+filename+":\n");
  for(i=0;i<sizeof(exfile);i++) {
    if(exfile[i]=="/* USERDOC:") {
      i++;
      function=exfile[i++];
      text="";
      functions+=({function});
      list+=function+"\n";
      while(exfile[i]!="*/") text+=exfile[i++]+"\n";
      texts+=({text});
    }
  }
  if(list=="") list="None.";
  NOTIFY
  this_player()->more_string(sprintf("%-*#s\n",SCREEN_WIDTH,list));
  return 1;
}

query_auto_load() {
  return "players/cashimor/objects/document:";
}

drop() {
  return 1;
}



