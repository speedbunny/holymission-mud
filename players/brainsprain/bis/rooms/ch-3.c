inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  short_desc = "Bismarck Hall";
  long_desc =
    "  To the south is a doorway into a tower.  On either side of the doorway\n"+
    "  is an ancient suit of armor with a halberd resting against their left\n"+
    "  shoulders.  The floor here is solid flagstones fit neatly together.\n"+
    "\n";
  set_light(1);
  dest_dir = ({
    br+"/ch-4.c","west",
    br+"/ch-2.c","east",
    br+"/t-1-1.c","south",
  });
  items = ({
    "doorway",
    "A doorway leading into a tower",
    "tower",
    "The southeastern tower of Castle Bismarck",
    "bismarck",
    "Castle Bismarck",
    "castle",
    "Castle Bismarck",   
    "armor",
    "Massive suits of armor in a baroque style",
    "halberd",
    "Six foot poles with double-bladed axe heads on the end",
    "flagstones",
    "Big stones",
    "floor",
    "It is made of neatly put together flagstones",
  });
  ::reset(arg);
  replace_program("room/room");
}
