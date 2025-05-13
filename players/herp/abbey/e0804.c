#include "abbey.h"
inherit "room/room";

reset(arg) {

  if (!arg) {
     set_light(1);
     short_desc="North end of courtyard";
     long_desc=
"You begin to hear and smell the domestic livestock kept by the monks.  You\n"+
"hear a pig squealing to the south.\n";
     dest_dir=({ PATH+"/e0803","west",
		 PATH+"/e0805","east",
		 PATH+"/e09s1","south" });
  }
}
