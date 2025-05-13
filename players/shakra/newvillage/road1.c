/*
 * Author : Uglymouth
 *  Date  : 9-AUG-1993
 */
#include "path.h"
inherit "room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc = "The beginning of Rich Men's Road";
  long_desc = "At this place Rich Men's road begins. It's still a dirt road here,\n"
        + "but it gets better further north, where it leads into the richer\n"
        + "part of the village. An intersection of roads lies south.\n";
  dest_dir = ({ PATH+"road2","north",
        PATH+"street4","south" });
  items = ({"rich men's road","This road leads into the richer part of the village and is paved further on",
        "road","It's a dirt road here, but it becomes a paved road north of here",
        "intersection","An intersection of roads in the centre of the village",
        });

  replace_program("room/room");
  }

