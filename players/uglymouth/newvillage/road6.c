/*
 * Author : Uglymouth
 * Date   : 10-AUG-1993
 */
#include "path.h"
inherit "room/room";

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc="Behind the northern village gate";
  long_desc="You stand right behind the northern village gate. Rich Men's Road runs\n"
        + "south from here. A small guard booth stands next to the gate.\n"
        + "Another road runs north from here into the wilderness.\n";
  dest_dir=({PATH+"road7","north",
        PATH+"road5", "south" });
  items=({
        "gate","A heavy gate in the wooden stockade that surrounds the village",
        "stockade","A defense wall made of sharply pointed poles",
	"rich men's road","A brick road, leading through the richer part of the village",
	"road","It's made of red bricks",
	"bricks","Red bricks",
	"booth","A shelter for the guard on duty. Right now it's empty",
	});
}

void init() {
  ::init();
  add_action("north","north");
}

north() {
  write("You open the gate and leave the village. The gate closes again behind you.\n");
  return 0;
}
