#include "abbey.h"
inherit "room/room";

reset(arg) {

  if (!arg) {
     set_light(1);
     short_desc="Courtyard";
     long_desc=
"You hear a pig squealing to the north.  You see a monk carrying a sack\n" +
"of grain out of a building to your east.  He heads across the courtyard\n" +
"west to the kitchen, before you can speak to him.\n";
     dest_dir=({ PATH+"/e11s1","north",
		 PATH+"/e12s2","east" });
  }
}
