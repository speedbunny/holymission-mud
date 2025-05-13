#include "abbey.h"
inherit "room/room";

reset(arg) {
  if (!arg) {
     set_light(1);
     short_desc="A dead end";
     long_desc=
"You have walked into what appears to be a dead end in the labyrinth.\n"+
"This room looks very much like all the others.\n"+
"Will this madness ever stop?\n";
     dest_dir=({ PATH+"/l11","east" });
  }
}
