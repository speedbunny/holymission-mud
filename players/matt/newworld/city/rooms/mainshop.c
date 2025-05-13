inherit "/room/shop";

#include "/players/matt/defs.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  set_short("Dyolf's Main Shop");
  set_long("    This is a small shop in Dyolf City. There is a sign on\n" +
	   "the north wall, and the exit lies to the south. The busy\n" +
	   "sounds of the city square are much less apparent here.\n");
  set_exits(({
    NWCITY + "rooms/square", "south",
  }));
  set_store_room(NWCITY + "rooms/mainstore");
  set_store_exit("north");
  items = ({
    "north wall", "The north wall contains a small sign",
    "wall", "A wall with a small sign hanging on it",
    "sign", "A small sign; you can read it",
  });
}

init() {
  ::init();
  add_action("read", "read");
}

read(arg) {
  if(arg == "sign" || arg == "small sign") {
    write("The sign has the standard shop commands written on it.\n");
    write("These commands are:\n");
    write(" - list\n");
    write(" - list armours\n");
    write(" - list weapons\n");
    write(" - buy <item>\n");
    write(" - sell <item>\n");
    write(" - sell all\n");
    write(" - value <item>\n");
    return 1;
  }
}
