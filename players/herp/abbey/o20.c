#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="South Path";
     long_desc=
"A narrow track hugging the abbey wall.\n";
     dest_dir=({ PATH+"/o19","east",
		 PATH+"/o21","west" });
  }
}
