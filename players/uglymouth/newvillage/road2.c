/*
 * Author : Uglymouth
 * Date   : 9-AUG-1993
 */
#include "path.h"
inherit "room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc = "The eastern corner of Rich Men's Road";
  long_desc = "You are at the eastern corner of Rich Men's Road. Here the road\n"
        + "changes from the dirt road from the south into a paved road\n"
        + "leading west. To the north lies a stone building.\n";
  dest_dir = ({ PATH+"bank","north",
        PATH+"road1","south",
        PATH+"road3","west" });
  items = ({"corner","From here the road turns leads south and west",
        "rich men's road","A paved road through the rich part of the village",
        "road","The road is made of red bricks, but covered with much sand from the south",
        "bricks","Red bricks are form a well layed roadsurface",
        "building","A building of yellow bricks. A sign on it reads: Forest Investers Coop., Bank",
        });
  }

void init() {
  ::init();
  add_action("north","north");
  }

north() {
  write("The bank is not yet open.\n");
  return 1;
  }
