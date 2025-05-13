inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Start of North Road";
  long_desc =
    "    This is North Road, a path made of tightly packed earth\n" +
    "and small stones. It seems rather well-traveled and worn down,\n" +
    "but it is still in good repair. There is a dense forest to the\n" +
    "west and the east, and you can travel either north or south on\n" +
    "the road itself. You can see mountains far to the north.\n"; 

  dest_dir = ({
    NWROAD + "rooms/road02", "north",
    NEWWORLD + "entry", "south",
  });

  items = ({
    "trees", "The trees are large and packed tightly together",
    "road", "North Road is made of hard-packed earth",  
    "stones", "They make up the road",
    "mountains", "Huge peaks reaching towards the sky",
    "forest", "The dense forest is on either side of you",
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
