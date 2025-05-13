inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "North Road";
  long_desc =
    "    You are on North Road. Northward you can see the road take\n" +
    "a bend to the right and enter a grassy plain, and directly\n" +
    "south of you is the Archway. The forest is quite thin at this\n" +
    "point on the road.\n" +
    "    There are two small signs here, one on the east side of\n" +
    "the path and one on the west.\n";

  dest_dir = ({
    NWROAD + "rooms/road04", "north",
    NWROAD + "rooms/road02", "south",
  });

  items = ({
    "trees", "The trees are sparse here",
    "road", "North Road is made of hard-packed earth",  
    "mountains", "Huge peaks reaching towards the sky",
    "forest", "The forest seems divided by this road",
    "west sign", "It says 'This way to the Western Forest'",
    "east sign", "It says 'This way to the Eastern Forest'",
    "sign", "Specify east or west sign",
    "signs", "Specify east or west sign",
    "archway", "You can see it in the distance to the south",
  });
}

init() {
  ::init();
  add_action("enter_a", "west");
  add_action("enter_b", "east");
  add_action("enter", "enter");
  add_action("read", "read");
}

enter_a() {
  write("You enter the Western Forest.\n");
  TP->MOVEP("into the Western Forest#" +
	    NWFORESTA + "rooms/a01");
  return 1;
}

enter_b() {
  write("You enter the Eastern Forest.\n");
  TP->MOVEP("into the Eastern Forest#" +
	    NWFORESTB + "rooms/b01");
  return 1;
}

enter(arg) {
  if(arg == "forest") {
    write("Enter which forest?\n");
    return 1;
  }
  else if(arg == "forest a" || arg == "a")
    enter_a();
  else if(arg == "forest b" || arg == "b")
    enter_b();
  else {
    write("Enter what?");
    return 1;
  }
}

read(arg) {
  if(arg == "sign") {
    write("Please specify east or west sign.\n");
    return 1;
  }
  if(arg == "east sign") {
    write("It says 'This way to the Eastern Forest.'\n");
    return 1;
  }
  if(arg == "west sign") {
    write("It says 'This way to the Western Forest.'\n");
    return 1;
  }
}
