inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"

tele(){
  remove_call_out("tele");
  write("Jasper transfers you to the great hall.\n");
  this_player()->move_player("to the great hall#/players/brainsprain/bis/rooms/grnd_hl.c");
  return 1;
}
int give(string arg){
  object sword;
  object tome;
  if(!arg || arg != "tome to duke" && arg != "tome to jasper"){
    write("Give what to whom.\n");
    return 1;
  }
  else if(!present("jasper")){
    write("The duke is not here to give it to.\n");
    return 1;
  }
  else if(!present("#QTOME#",this_player())){
    write("You do not have the tome!\n");
    return 1;
  }
  else {
    tome = present("#QTOME#",this_player());
    destruct(tome);
    write("Duke Jasper says: Why thank you very much!!\n"+
	  "The duke casts a spell on a sword.\n"+
	  "Duke Jasper says: Use this to kill Darkstaff.\n");
    sword = clone_object(q+"/qsword.c");
    move_object(sword,this_player());
    tele();
    return 1;
  }
}

void reset(int arg) {
  clone_list = ({ 1, 1, "jasper", bm+"/jasper.c", 0 });
  ::reset(arg);
  if(arg) return;
  short_desc = "Duke Jasper's workroom";
  long_desc =
    "Bottles and vials lay in haphazard stacks on a table in the center of "+
    "this room.  A massive cauldron bubbles and sends pink fumes curling "+
    "up to the ceiling.  Several bookshelves house many tomes of magical lore.\n";
  set_light(1);
  items = ({
    "cauldron",
    "Duke Jasper must be mixing something up",
    "fumes",
    "Pink fumes coming from the cauldron",
    "bookshelves",
    "Shelves holding tomes of magic lore",
    "tomes",
    "Magic tomes containing magic spells",
    "bottles",
    "Bottle lay in haphazard stacks",
    "vials",
    "Vials lay in haphazard stacks",
    "table",
    "It is in the center of the room",
    "room",
    "Duke Jasper's magic room",
  });
  dest_dir = ({
    br+"/sec-1.c","north",
    br+"/t-3-2.c","leave",
  });
}
void init(){
  ::init();
  add_action("give","give");
}



