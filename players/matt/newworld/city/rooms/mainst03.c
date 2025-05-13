inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Main Street";
  long_desc =
    "    This is the western section of Main Street. East of here is\n" +
    "the city square, and the street continues to the west. The huge\n" +
    "mass of people is thinner here, and on the side of the road you\n" +
    "notice a small booth.\n";

  dest_dir = ({
    NWCITY + "rooms/mainst04", "west",
    NWCITY + "rooms/square", "east",
  });
  
  items = ({
    "square", "The crowded central area of the city",
    "street", "Main street is a worn, well-used street running through Dyolf",
    "mass", "A large mass of people",
    "people", "Many people busily line the streets",
    "booth", "A small booth on the side of the road",
  });
}

init() {
  ::init();
  add_action("enter", "enter");
}

enter(arg) {
  if(arg == "booth") {
    write("You enter the small booth.\n");
    TP->MOVEP("into the booth#" + NWCITY + "rooms/votebooth");
    return 1;
  }
  write("Enter what?\n");
  return 1;
}
