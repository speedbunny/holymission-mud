#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Stairs";
     long_desc=
"You are climbing a long set of stairs through what appears to be\n"+
"nearly open space.  The only light is from the torches in the\n"+
"room that these stairs are connected to.\n";
     dest_dir=({ PATH+"/l07","northeast",
		 PATH+"/l04","south",
		 PATH+"/l06","north" });
  }
}
