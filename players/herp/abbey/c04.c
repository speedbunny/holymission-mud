#include "abbey.h"
inherit "room/room";

reset(arg) {
object ob;
  if (!arg) {
     set_light(1);
     short_desc="End of corridor";
     long_desc=
"You stand at the end of a dark stone corridor.  It is cold and damp.\n"+
"You hear water dripping.\n";
     dest_dir=({ PATH+"/c03","north",
		 PATH+"/c05","east" });
  }
}
