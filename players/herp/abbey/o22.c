#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="West Path";
     long_desc=
"You are on a narrow, icey path hugging the abbey wall on your east.  The path\n"+
"continus north and south.\n";
     dest_dir=({ PATH+"/o23","north",
		 PATH+"/o21","south" });
  }
}
