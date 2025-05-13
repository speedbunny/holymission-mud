#include "abbey.h"
inherit "room/room";

reset(arg) {
int i;

  if (!arg) {
     set_light(1);
     short_desc="Intersection, South Courtyard";
     long_desc=
"You are in the southern part of the abbey courtyard.  To your east and west\n"+
"appear living quarters.  To the south, the chapel.  You see a huge black\n"+
"tower to the southwest.\n";
     items=({
	"chapel","The ancient chapel, whose on fame is it's age",
	"tower","A huge, black, forbidding tower" });
     dest_dir=({ PATH+"/e14","north",
		 PATH+"/e16","south",
		 PATH+"/m01","east",
		 PATH+"/s01","west" });
  }
}
