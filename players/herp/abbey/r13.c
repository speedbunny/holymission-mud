#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
  if (!arg) {
     set_light(1);
     short_desc="Passage";
     long_desc=
"A dimly lit hallway, stretching out of sight north and south.  You see\n"+
"footprints in the dust.\n";
     dest_dir=({ PATH+"/r12","north",
		 PATH+"/r14","south" });
  }
}
