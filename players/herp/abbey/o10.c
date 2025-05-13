#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="On the east path";
     long_desc=
"The cold abbey wall forbids passage to the west, the hill is preciptious\n"+
"and unclimbable to the east.\n";
     dest_dir=({ PATH+"/o09","north",
		 PATH+"/o11","south" });
  }
}
