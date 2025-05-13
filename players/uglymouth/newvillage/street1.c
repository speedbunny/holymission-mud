/*
 * Author : Uglymouth
 * Date   : 4-AUG-1993
 */
#include "path.h"
inherit "room/room";

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc="Village entrance";
  long_desc="The forest gives away here and a decent road leads east to a village.\n"
        + "The village is surrounded by a high wooden stockade to keep out the\n"
        + "dangers of the forest. You're about to enter through the gate.\n";
  dest_dir=({"/players/moonchild/deep_forest/f3-8","east",
        PATH+"street2", "west" });
  items=({
        "forest","A huge forest awaits you silently",
        "road","A well-maintained dirt road",
        "village","A woodsmen's village. It looks a bit like the central village",
        "stockade","A wall of pointed wooden poles",
        "dangers","You have to enter the forest to find them",
        "gate","A guarded gate in the stockade leads to the village proper", });
}

void init() {
  ::init();
  add_action("west","west");
}

west() {
   write("A guard opens the gate and lets you through. \n"
      + "The guard closes the gate behind you.\n");
   return 0;
   }
