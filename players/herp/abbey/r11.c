#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
  if (!arg) {
     set_light(1);
     short_desc="Passage";
     long_desc=
"The dim passage.  You see footprints in the dust.\n";
     dest_dir=({ PATH+"/r10","north",
		 PATH+"/r12","south" });
  }
}
