#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="On some stairs";
     long_desc=
"You are walking up another set up stairs in the huge labyrinth.\n";
     dest_dir=({ PATH+"/l11","up",
		 PATH+"/l06","southeast" });
  }
}
