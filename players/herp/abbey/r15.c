#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
  if (!arg) {
     set_light(1);
     short_desc="Passage";
     long_desc=
"You are in a dim hallway.  Dust is everywhere.\n";
     dest_dir=({ PATH+"/r14","north",
		 PATH+"/r16","south" });
  }
}
