#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="South Path";
     long_desc=
"An icey path south of the abbey wall.\n";
     dest_dir=({ PATH+"/o16","east",
		 PATH+"/o18","west" });
  }
}
