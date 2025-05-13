/*
 * Author : Uglymouth
 * Date   : 10-AUG-1993
 */
#include "path.h"
inherit "room/room";

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc="Just outside the northern village gate";
  long_desc="You stand just outside the northern gate into the village. The village\n"
        + "is surrounded by a wooden stockade to keep any dangers out. A road leads\n"
        + "north into the wilderness. The gate stands a few inches open.\n";
  dest_dir=({PATH+"road8","north",
        PATH+"road6", "south" });
  items=({
        "gate","A heavy gate form the northern entrance to the village",
        "stockade","A wooden defense wall, made of sharply pointed poles",
	"village","It's behind the gate",
	"road","Just another dirt road, like so many",
	});
}

void init() {
  ::init();
  add_action("south","south");
  add_action("north","north");
}

south() {
  write("As you pull at the gate it opens and you enter the village.\n");
  return 0;
}

north() {
  write("The heavy rainfall of the last few days has made it impossible to use this road.\n");
  return 1;
}
