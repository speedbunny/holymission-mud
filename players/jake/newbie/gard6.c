inherit "room/room";

#include "/players/jake/defs.h"
reset (arg) {
if (arg) return;
set_light(3);
short_desc = "gard6";
long_desc = "A small clearing.\n"
+  "You hear thumping noises to the east.\n"
+  "You get a very peaceful feeling from this place.\n";
 DD = ({
 NEW + "gard8","south",
 NEW + "bunnyroom","east",
});
}
