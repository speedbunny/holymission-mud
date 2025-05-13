inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "North Road";
  long_desc =
    "    North Road continues north towards the mountains and south\n" +
    "back to the Archway. The forest is somewhat sparse here, but it\n" +
    "looks a bit too thick to enter.\n";

  dest_dir = ({
    NWROAD + "rooms/road03", "north",
    NWROAD + "rooms/road01", "south",
  });

  items = ({
    "trees", "The trees are rather thin here",
    "road", "North Road is made of hard-packed earth",  
    "mountains", "Huge peaks reaching towards the sky",
    "forest", "A dark and forbidding forest",
  });
}

init() {
  ::init();
  add_action("no_way", "west");
  add_action("no_way", "east");
}
        
no_way() {
  write("The forest is too thick here.\n");
  return 1;
}
