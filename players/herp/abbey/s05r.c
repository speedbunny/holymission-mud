#include "abbey.h"
inherit "room/room";

reset(arg) {
int i;

  if (!arg) {
     set_light(1);
     short_desc="Large Bedroom";
     long_desc=
"You have entered a large bedroom.  From the size you would\n"+
"guess the occupant of this room to be highly honored from\n"+
"his fighting prowess.\n";
     dest_dir=({ PATH+"/s05","west" });
  }
}
