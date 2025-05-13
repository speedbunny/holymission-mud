#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Mule Track";
     long_desc=
  "A path usually trod by mule trains, that climbs up through the\n"+
  "forest.  The snowy mountain path lies north.  There is a sign here.\n";
     items=({ "sign",
	"The sign says: Europe, Italy, 1056 a.d.\nWelcome to the Abbey "+
	"of the Rose.\nCredit is given to Umberto Ecco, Forlock and "+
	"Flamme" });
     dest_dir=({ PATH+"/i02","north",
		 PATH+"/e02","south" });
  }
}

init() {
  ::init();
  add_action("read","read");
}

read(str) {
  if (str=="sign")
  ::long(str);
  return 1;
}
