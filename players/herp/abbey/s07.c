

#include "abbey.h"
inherit "room/room";

reset(arg) {

  if (!arg) {
     set_light(1);
     short_desc="Empty Room";
     long_desc=
"You have entered a nicely furnished room.  The occupant has just\n"+
"stepped out for a moment.  You had better not steal anything!\n";
     dest_dir=({ PATH+"/s06","south" });
  }
}
