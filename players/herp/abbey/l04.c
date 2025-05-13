#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="The Entrace to the Labyrinth";
     long_desc=
"You have entered what apears to be a huge labyrinth of\n"+
"library rooms.  Old books line the shelves of all rooms\n"+
"in this place.  Stairs seem to run off in all directions.\n"+
"Maybe you should get out of here, to the west, before you get lost?\n";
     dest_dir=({ PATH+"/l05","north",
		 PATH+"/l03","west" });
  }
}
