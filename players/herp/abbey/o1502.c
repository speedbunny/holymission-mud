#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Cliff Overlook";
     long_desc=
"You look over a rocky drop to the valley far below, at the foot of which you see\n" +
"a mule track, with a caravan wending it's way slowly upwards.\n";
     dest_dir=({ PATH+"/o15","west" });
  }
}
