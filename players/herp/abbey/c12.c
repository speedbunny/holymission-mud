#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Courtyard";
     long_desc=
"You see monks entering the kitchen areas to your west.  Other monks are\n"+
"returning from the baths to the south.  They are damp and clean, a rarity.\n";
     dest_dir=({ PATH+"/c13","west",
		 PATH+"/e0801","north",
		 PATH+"/c11","south" });
  }
}
