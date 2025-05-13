#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Intersection";
     long_desc=
"The footpath hugs the abbey wall to the east and south.  To the north\n"+
"is a well-travelled path.  To the west, a faint track heads towards the\n"+
"cliff-top.  Above you, you see a huge mass of garbage sliding out of the abbey\n" +
"garbage-sluice.  Starving peasants fight over rotted grain, moldy cabbage\n"+
"leaves and fruit rinds.\n";
     dest_dir=({ PATH+"/o0201","north",
		 PATH+"/o27","south",
		 PATH+"/o03","east",
		 PATH+"/o01","west",
		 PATH+"/c01","up" });
  }
}
