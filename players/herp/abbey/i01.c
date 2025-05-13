#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Slope";
     long_desc=
"You stand on a steep slope passing up through the\n"+
"tree line to the east, and onto the shoulder of a\n"+
"vast, snow covered mountain.  You shiver in the chill\n"+
"wind blowing off the craggy rock slopes.\n";
     dest_dir=({ "room/south/sforst17","north",
		 PATH+"/i02","east" });
  }
}
