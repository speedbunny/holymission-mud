inherit "room/shop";

#include "/players/redsexy/guild/guilddefs.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  set_short("Summoner Magic Shop");
  set_long("    This is a Magic Shop, containing magical wares for\n" +
	   "Summoners. A shopkeep stands behind a black counter, toying\n" +
	   "with a small figurine as his eyes follow you beneath the\n" +
	   "dark hood concealing his face.\n" +
	   "    A small cubicle sits in one corner of the room; upon\n" +
	   "its floor is drawn a complicated Rune-circle. Hanging on\n" +
	   "the north wall is a small sign.\n");
  set_exits(({ PATH + "rooms/lounge", "north"}));
  set_store_room(PATH + "rooms/magicstore");
  set_store_exit("south");
  items = ({
    "shop", "A place to magical items",
    "north wall", "The north wall contains a small sign",
    "wall", "A wall, upon which hangs a small sign",
    "sign", "A small sign that you could probably read",
    "shopkeep", "A black-robed shopkeep watching you carefully",
    "wares", "The wares of the shop",
    "figurine", "This figurine resembles the many behind the counter",
    "hood", "The dark hood of the shopkeep",
    "floor", "On the floor of the cubicle, a Rune-circle is drawn",
    "rune-circle", "A complex series of spiderly lines drawn on the floor",
    "circle", "This is a complex Rune-circle. Perhaps you can enter it",
    "cubicle", "A small black cubicle in the corner, which you could enter",
    "corner", "The corner of the room contains a small cubicle",
  });
}

init() {
  ::init();
  add_action("read", "read");
  add_action("enter", "enter");
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

enter(arg) {
  if(arg == "circle" || arg == "rune-circle" ||
     arg == "cubicle") {
    write("You step into the circle, and find yourself transported!\n\n");
    TP->MOVEP("into the cubicle#" +
	      "room/church");
    return 1;
  }
  write("Enter what?\n");
  return 1;
}
