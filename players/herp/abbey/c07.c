#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
  if (!arg) {
     set_light(1);
     short_desc="Bath corridor";
     long_desc=
"You are in a slimey, mildew scented corridor.\n";
     dest_dir=({ PATH+"/c08","north",
		 PATH+"/c09","east",
		 PATH+"/c05","west" });
  }
}
