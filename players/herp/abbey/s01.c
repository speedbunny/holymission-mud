#include "abbey.h"
inherit "room/room";

reset(arg) {
int i;

  if (!arg) {
     set_light(1);
     short_desc="Southern Courtyard";
     long_desc=
"You stand in the southern court of the courtyard.  To your south you see the\n"+
"vast chapel complex.  To your east and west appear to be living quarters.\n"+
"There is a huge tower in the southwestern corner.\n";
     dest_dir=({ PATH+"/e15","east",
		 PATH+"/s02","west" });
  }
}
