#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Trail";
     long_desc=
"You are on at a crossroads on the trail.  The stench of burnt flesh is\n" +
"thick.  Smoke drifts lazily across the trail, and you hear an incompre-\n" +
"hensible singing from the south.\n";
     dest_dir=({ PATH+"/o18","north",
		 PATH+"/o18tr","southeast",
		 PATH+"/o18tm","south",
		 PATH+"/o18tl","southwest" });
  }
}
