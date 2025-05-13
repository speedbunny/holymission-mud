#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Labyrinthe";
     long_desc=
"You are standing in the highest room in the labyrinthe.  You feel dizzy.\n";
     dest_dir=({ PATH+"/l25","west",
		 PATH+"/r01","south" });
  }
}

init() {
  ::init();
  add_action("south","south");
}

south() {
  write("You walk through the end of the labyrinth.\n");
  return ::move("south");
}
