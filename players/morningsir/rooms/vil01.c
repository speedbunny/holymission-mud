inherit "/room/room";

#include "/players/morningsir/defs.h"

reset(arg) {
  if(!arg) {

  set_light(1);
  short_desc="Near the bank";
  long_desc=
   "You are standing at an open place near the river. You can hear the rippling\n" +
   "water from the western direction. A little forest can be seen to the east,\n" +
   "and there is a sound of wolves coming from it. At this place a dirty road\n" +
   "starts and continues to the east.\n";

  dest_dir=({ PATHR + "vil02.c", "east"
             });

  items=({ "river", "The river is flowing pretty fast.",
           "forest", "The forest doesn't seem too dense to enter.",
           "trees", "The trees look like pines.",
           "road", "It's a forest road, quite dirty, but dry after all."
          });
  }
 replace_program("room/room");
}
