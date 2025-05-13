#include "abbey.h"
inherit "room/room";

reset(arg) {
int i;

  if (!arg) {
     set_light(1);
     short_desc="Central Courtyard";
     long_desc=
"You stand in the center of the Abbey.  You see small groups of monks\n" +
"bustling about their daily chores.\n" +
"Directly south is the chapel.  You hear singing.\n";
     dest_dir=({ PATH+"/e11","north",
		 PATH+"/e13","south" });
  }
}
