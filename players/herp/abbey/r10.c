#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
  if (!arg) {
     set_light(1);
     short_desc="Passage";
     long_desc=
"You stand in a dim passage.  There are signs in the dust of recent footprints.\n";
     dest_dir=({ PATH+"/r07","north",
		 PATH+"/r11","south" });
  }
}
