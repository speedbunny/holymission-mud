#include "abbey.h"
inherit "room/room";

reset(arg) {
int i;

  if (!arg) {
     set_light(1);
     short_desc="Central Courtyard";
     long_desc=
"You stand at the north end of a vast entral courtyard.  You see the many\n" +
"utilitarian buildings of this magnificent abbey arrayed all around you.\n" +
"Monks, heavily robed against the bitter cold, hustle from building to\n" +
"building, carrying out the days work.\n";
     dest_dir=({ PATH+"/e08","north",
		 PATH+"/e10","south" });
  }
}
