#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
int i;

  if (!arg) {
     set_light(1);
     short_desc="Upper landing";
     long_desc=
"You are in an ancient stairwell.  Cobwebs brush your face as you move and\n"+
"you hear the scurrying and squeaking of many rats.\n";
     dest_dir=({ PATH+"/r04","west",
		 PATH+"/g08","down" });
  }
}
