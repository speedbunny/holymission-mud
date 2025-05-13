#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Entry to baths";
     long_desc=
"You are in a dark, stone corridor.  It is cold, icey in spots, and\n"+
"smells of unwashed bodies and sour, wet clothes.\n";
     dest_dir=({ PATH+"/c12","north",
		 PATH+"/c09","west" });
  }
}
