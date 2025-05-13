#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Mule Track";
     long_desc=
  "A path usually trod by mule trains, that climbs up through the\n"+
  "forest.  The landscape is rough and craggy.\n";
     dest_dir=({ PATH+"/e01","north",
		 PATH+"/e03","south" });
  }
}
