#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="Great Hall";
     long_desc=
"You enter a huge, cavernous room, heated by fireplaces at both ends.  It is\n"+
"filled with trestle tables and benches.  The monks take their meal here,\n"+
"as well as meet for spiritual discussions and special sermons.  A cross\n"+
"hangs prominently displayed on one wall, a large carving of a rose on\n"+
"another.\n";
     dest_dir=({ PATH+"/c14","north",
		 PATH+"/c18","west",
		 PATH+"/c12","east" });
  }
}
