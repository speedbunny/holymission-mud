/*
 * Author : Uglymouth
 * Date : 9-AUG-1993
 */
#include "path.h"
inherit "room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc = "The east - west section of Rich Men's Road";
  long_desc = "You walk on the east - west section of Rich Men's Road. To the east\n"
        + "The road turns south, to the west it turns north again. South\n"
        + "you look at the blind wall of a builing.\n";
  dest_dir = ({ PATH+"road2","east",
        PATH+"road4","west" });
  items = ({"rich men's road","The road through the richer part of the village",
        "road","A well paved road of red bricks",
        "bricks","Red bricks form the roadsurface",
        "wall","The wooden wall of a building. A sign on it says: Pub entrance at the square",
        "building","A wooden building, like most buildings in this village",
        });

  replace_program("room/room");
  }

