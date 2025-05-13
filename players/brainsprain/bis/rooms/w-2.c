inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {

  short_desc = "The peasants waiting room";
  long_desc =
"A row of plain wooden benches fills this room.  To the north is a room "+
"Where those waiting for an audience with the Count can get refreshments. "+
"To the southeast is the throneroom. There is a small painting on the wall.\n";
  set_light(1);
  items = ({
    "painting",
    "A painting of Count Bismarck",
    "count",
    "Count Bismarck",
    "bismarck",
    "The name of the ruling family",
    "benches",
    "Wooden benches",
    "room",
    "A room filled with refreshments",
    "refreshments",
    "Food and wine",
    "entrance",
    "Entrance to the throne room",
  });
  dest_dir = ({
    br+"/w-1.c","north",
    br+"/a-2.c","east",
    br+"/throne.c","southeast",
  });
clone_list = ({ 1, 4, "peasant", bm+"/peas.c", 0 });
   ::reset(arg);
    replace_program("room/room");
}
