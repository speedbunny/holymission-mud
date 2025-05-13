#include "abbey.h"
inherit "room/room";

reset(arg) {

  if (!arg) {
     set_light(1);
     short_desc="North Courtyard";
     long_desc=
"The northern end of the Abbey courtyard.  The baths and kitchens lie to\n"+
"the south.\n";
     dest_dir=({ PATH+"/e0802","east",
		 PATH+"/c12","south" });
  }
}
