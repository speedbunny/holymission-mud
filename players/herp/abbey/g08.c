#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
int i;

  if (!arg) {
     set_light(1);
     short_desc="On the stairs";
     long_desc=
"You are in a narrow, cobwebby stairwell.\n";
     dest_dir=({ PATH+"/g09","up",
		 PATH+"/g07","east" });
  }
}
