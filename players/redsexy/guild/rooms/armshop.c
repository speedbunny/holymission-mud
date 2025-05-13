inherit "room/shop";

#include "/players/redsexy/guild/guilddefs.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  set_short("Armoury of Summoners");
  set_long("    This is the Armoury, a place where you can equip yourself\n" +
	   "with weapons and armours that will still allow you to cast\n" +
	   "all of your spells without hindrance. A shopkeep watchfully\n" +
	   "stands behind a smooth stone counter, and behind him his\n" +
	   "wares are displayed.\n");
  set_exits(({ PATH + "rooms/lounge", "east" }));
  set_store_room(PATH + "rooms/armstore");
  set_store_exit("west");
  items = ({
    "shop", "A place to buy weapons and armour",
    "north wall", "The north wall contains a small sign",
    "wall", "A wall, upon which hangs a small sign",
    "sign", "A small sign that you could probably read",
    "shopkeep", "A darkly-garbed shopkeep carefully watching his wares",
    "wares", "The wares of the shop",
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
