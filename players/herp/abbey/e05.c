#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="On the Ridge";
     long_desc=
"You follow the grim and rocky trail along the ridgetop.  The cold wind cuts\n"+
"through your clothes and sets your teeth chattering.  To the west you see a\n"+
"gypsy riding a mule to his camp.  To the south you see a cold and forbidding\n"
+"Abbey.\n";
     dest_dir=({ PATH+"/e04","north",
		 PATH+"/e06","south" });
  }
}
