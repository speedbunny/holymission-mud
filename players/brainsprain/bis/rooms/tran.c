inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"

int read (string str){
  if (str != "sign"){
    write ("Read What?\n");
    return 1;
  }
  else {
    write (
	   //                "  Transfers to Spiral Island available.\n"+
	   //                "  Syntax:  trans me\n"+
	   "  No destinations currently available.\n"+
	   "\n");
    return 1;
  }
}

int trans (string arg){
  if (!present("man",TO)){
    write (" There is no one here to transfer you!\n");
    return 1;
  }
  else if(arg != "me"){
    write (" The Old man says:  Sorry, I dont know who that is.\n");
    return 1;
  }
  else if(arg == "me"){
    /*
      write(
      "  The old man graciously accepts your money and transfers you.\n"+
      "  You land with a thud somewhere on Spiral Island.\n");
      this_player()->move_player("into a transfer cloud#/players/aryk/spiral/i
      sland/isla5.c");
      this_player()->move_player("into a transfer cloud#/players/aryk/spiral/i
      sland/isla5.c");
      return 1;
      }
      */
    write("This transfer shop is out of order\n");
  }
}

void reset(int arg) {
  clone_list = ({ 1, 1, "Old Man", bm+"/old_dude", 0 });
  :: reset(arg);
  if(arg) return;

  short_desc = "Mystical Transport Room";
  long_desc =
    "A pentagram covers virtually the entire floor.  The walls are covered "+
    "with mirrors focusing all the light into the center of the room. Thick "+
    "drapes cover all of the windows.  An ominous hum echos off the walls. "+
    "A sign is nailed to the wall.\n";
  set_light(1);
  dest_dir = ({
    br+"/tr-12","east",
  });
  items = ({
    "drapes",
    "They cover all of the windows",
    "Windows",
    "There are four windows covered with drapes",
    "floor",
    "The floor of the Mystical Transport Room",
    "walls",
    "They are covered with mirrors",
    "room",
    "The Mystical Transport Room",
    "pentagram",
    "A protective ward for transfering",
    "mirrors",
    "They focus mystic energy",
    "sign",
    "A sign with faded letters",
  });
}
void init (){
  ::init();
  add_action("read","read");
  add_action("trans","trans");
}

