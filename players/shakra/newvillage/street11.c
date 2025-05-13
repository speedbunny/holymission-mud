/*
 * Author : Uglymouth
 * Date   : 9-AUG-1993
 */
#include "path.h"
inherit "room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc = "Behind the western gate";
  long_desc = "You stand just behind the western gate of the village. A small\n"
        + "guard booth stands next to the gate. The gate is closed to keep\n"
        + "unwanted visitors out. Main Street leads east from here.\n";
  dest_dir = ({ PATH+"street10","east",
        PATH+"street12","west" });
  items = ({"gate","A guarded gate in the stockade that surrounds the village",
        "stockade","A wooden defense wall that protects the village against the regular\n" 
                 + "dangers from outside",
        "booth","A small and simple shelter for the guard on duty",
        "main street","The major road through the village",
        "road","A well maintained dirt road",
        });

  clone_list = ({ 1, 1, "guard", "obj/monster", ({ "set_name","village guard",
    "set_alias","guard","set_level",1+random(3),"set_gender",1+random(2),
    "set_race","human" }),
    -1, 1, "spear", "obj/weapon", ({ "set_name","spear","set_class",7,
    "set_value",20 }) });
  ::reset();

  }

void init() {
  ::init();
  add_action("west","west");
  }

west() {
  if(present("village guard"))
    write("The guard opens the gate to let you out.\n"
      + "The guard tells you: Good luck. Hope to see you back alive another day.\n"
      + "The guard closes the gate carefully behind you.\n");
  else write("You leave the village through the western gate.\n");
  return 0;
  }
