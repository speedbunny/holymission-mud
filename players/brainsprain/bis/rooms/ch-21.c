inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  
  short_desc = "A secret part of Bismarck Hall";
  long_desc =
    "This is a secret part of Bismarck Keep.  There is no dust on the floors "+
    "though.  Old doors sit rotting on their hinges and the sound of groaning "+
    "wood comes from far in the distance.  There is a ladder going down.\n";
  set_light(1);
  dest_dir = ({
    br+"/ch-22.c","south",
    br+"/b-3.c","down",
  });
  items = ({
    "floors",
    "Despite the supposed secret nature of this area, no dust has accumulated",
    "hinges",
    "Rusty, old door hinges",
    "keep",
    "Castle Bismarck",
    "castle", 
    "Castle Bismarck",
    "bismarck",
    "Castle Bismarck",
    "doors",
    "Old, rotting doors",
    "ladder",
    "A ladder leading into the basement",
  });
  clone_list = ({ 1, 1, "guard", bm+"/guard.c", 0 }); 
  ::reset(arg);
  replace_program("room/room");
}
