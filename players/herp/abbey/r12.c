#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
  if (!arg) {
     set_light(1);
     short_desc="Passage";
     long_desc=
"A dim passageway stretches north and south.  You see footprints.\n";
     dest_dir=({ PATH+"/r11","north",
		 PATH+"/r13","south" });
  }
}
