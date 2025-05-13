inherit "/room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  
  short_desc = "The nobles waiting room";
  long_desc =
    "A row of plush cushioned wooden benches fill this room.  To the north "+
    "is a room where those waiting can recieve gourmet refreshments.  To "+
    "the southwest is the entrance to the throne room.\n";
  set_light(1);
  items = ({
    "benches",
    "Plump, cushioned, benches",
    "room",
    "A room filled with refreshments",
    "refreshments",
    "Food and wine",
    "entrance",
    "Entrance to the throne room",
  });
  dest_dir = ({
    br+"/e-1.c","north",
    br+"/a-2.c","west",
    br+"/throne.c","southwest",
  });
  clone_list = ({ 1, 5, "nobel", bm+"/nobl.c", 0 });
  ::reset(arg);
  replace_program("room/room");
}


