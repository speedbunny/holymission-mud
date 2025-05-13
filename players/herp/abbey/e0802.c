#include "abbey.h"
inherit "room/room";

reset(arg) {

  if (!arg) {
     set_light(1);
     short_desc="Courtyard North";
     long_desc=
"You stand on the ancient, uneven paving stones at the north end of a vast\n"+
"central courtyard in the Abbey.  Monks bustle about their daily chores\n"+
"well bundled against the harsh winter.\n";
     dest_dir=({ PATH+"/e08","east",
		 PATH+"/e0801","west" });
  }
}
