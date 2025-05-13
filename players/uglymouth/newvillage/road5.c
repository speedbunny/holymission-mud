/*
 * Author : Uglymouth
 * Date   : 9-AUG-1993
 */
#include "path.h"
inherit "room/room";

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc="The northern part of Rich Men's Road";
  long_desc="You stand on the northern part of Rich Men's Road. Further to the north\n"
        + "you see the northern gate out of the village. West stands a stone\n"
        + "building waiting for a wizard to make it into something.\n";
  dest_dir=({PATH+"road6","north",
        PATH+"road4", "south" });
  items=({
        "rich men's road","The brick road through the richer part of the village",
        "road","A paved road, made of red bricks",
	"bricks","Red bricks form the roadsurface",
	"gate","A strong wooden gate in the stockade that surrounds the village",
	"stockade","A wooden defense wall, made of sharply pointed poles",
	});

  replace_program("room/room");
}

