#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="West Path";
     long_desc=
"A narrow, icey track, hugging the abbey walls.\n";
     dest_dir=({ PATH+"/o24","north",
		 PATH+"/o22","south" });
  }
}
