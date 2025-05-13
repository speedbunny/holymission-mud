/*
 * Author : Uglymouth
 * Date   : 9-AUG-1993
 */
#include "path.h"
inherit "room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc = "The western corner of Rich Men's Road";
  long_desc = "You've arrived at the western corner of Rich Men's Road. From here\n"
        + "the road leads north and east. To the south stands a stone house\n"
        + "empty, waiting for a wizard to open a shop there.\n";
  dest_dir = ({ PATH+"road5","north",
        PATH+"road3","east",
        });
  items = ({"corner","From here the red brick road leads north and east",
        "rich men's road","The road leading through the richer part of the village",
        "road","A well paved road, made of red bricks",
        "bricks","It looks like the red brick roadsurface is cleaned quite often",
        "house","A house, built of yellow bricks",
        });

  replace_program("room/room");
  }

