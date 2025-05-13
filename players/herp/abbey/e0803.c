#include "abbey.h"
inherit "room/room";

reset(arg) {

  if (!arg) {
     set_light(1);
     short_desc="Courtyard North";
     long_desc=
"You stand at the northeastern area of the vast Abbey courtyard.  To your\n"+
"south you hear a pig squealing.  You see heavily robed monks scurrying\n"+
"from place to place, about their daily chores.\n";
     dest_dir=({ PATH+"/e0804","east",
		 PATH+"/e08","west" });
  }
}
