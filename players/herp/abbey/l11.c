#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="A large room in the labyrinth";
     long_desc=
"You have enterd a large room in the labyrinth somewhere.\n"+
"Books line the shelves in this room.  You still haven't found\n"+
"the one you want.\n";
     dest_dir=({ PATH+"/l08","down",
		 PATH+"/l14","west",
		 PATH+"/l15","up" });
  }
}
