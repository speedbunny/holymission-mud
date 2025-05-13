#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Small path";
     long_desc=
"A little-used path, big enough for one person at a time.\n";
     dest_dir=({ PATH+"/o07","north",
		 PATH+"/o10","south" });
  }
}
