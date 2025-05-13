#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Eastern path";
     long_desc=
"The dark stone of the abbey wall is to your west.  The icey path continues\n"+
"north and south.\n";
     dest_dir=({ PATH+"/o12","north",
		 PATH+"/o14","south" });
  }
}
