inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"

int read (string str){
  if (str != "sign"){
    write ("Read What?\n");
    return 1;
  }
  else {
    write (
	   "               This is the procedure to read a scroll:\n"+
	   "               Syntax: study about (subjectname)\n"+
	   "               Try the index for a list of scrolls\n"+
	   "\n");
    return 1;
  }
}
int do_ind (string arg){
  if(!arg){
    write ("These are the things we have scrolls about:\n"+
	   "                                                   count bismarck\n"+
	   "                                                   bismarck keep\n"+
	   "                                                   towpath\n"+
	   "                                                   spiral island\n"+
	   "                                                   dwarven brothers\n"+
	   "\n");
    return 1;
  }
  if(arg){
    write ("What ?\n");
  }
}
int do_study (string arg){
  if(present("librarian",TO)){   
    write (" There is no one here to give you a scroll!\n");
    return 1;
  }
  else if(arg == "about castle"){
    write("Old man says:  Here is the scroll about Bismarck Keep.\n"+
          "\n"+
          "\n");
    cat(bi+"/cas_sc.c");
    return 1;
  }
  else if(arg == "about dwarven brothers"){
    write("Old man says:  Here is the scroll about Bismarck Keep.\n"+
          "\n"+
          "\n");
    cat(bi+"/dw_sc.c");
    return 1;
  }
  else if(arg == "about towpath"){
    write("Old man says: Here is the scroll about Towpath.\n"+
          "\n"+
          "\n");
    cat(bi+"/tow_sc.c");
    return 1;
  }
  else if(arg=="about spiral island"){
    write("Old man says: Here is the scroll about Spiral Island.\n"+
          "\n"+
          "\n");
    cat(bi+"/spi_sc.c");
    return 1;
  }
  else if(arg=="about count bismarck"){
    write("Old mans says: Here is the scroll about the Count Bismarck.\n"+
	  
          "\n"+
          "\n")+
      cat(bi+"/co_sc.c");
    return 1;
  }
  else {
    write("Sorry we don't have a history on that subject!\n");
    return 1;
  }
}

void reset(int arg) {
  clone_list = ({ 1, 1, "librarian", bm+"/librarian", 0 });    
  ::reset(arg);
  if(arg) return;
    short_desc = "Towpath Archive";
    long_desc =
      "This is the the Archive room, it is here to allow citizens or visitors "+
      "to read about Bismarck Island or any of the surrounding islands. Scrolls "+
      "are stacked on shelves filling the entire room.  Torches line the walls "+
      "draping the center of the room in shadows.  A sign is affixed to the wall.\n";
    set_light(1);
    dest_dir = ({
      br+"/tr-17.c","west",
    });
    items = ({
    "shelves",
    "shelves filled with scrolls",
    "torches",
    "These torches throw light into the room",
    "room",
    "The archive room",
    "scrolls",
    "These scrolls tell the history of this part of the world",
    "sign",
    "A sign giving the command to read a scroll",
  });
  }
void init (){
  ::init();
  add_action("read","read");
  add_action("do_study","study");
  add_action("do_ind","index");
}

