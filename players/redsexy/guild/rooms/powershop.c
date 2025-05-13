inherit "room/room";

#include "/players/redsexy/guild/guilddefs.h"

#define COST 2

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Power Shop";
  long_desc =
    "    You stand in a cube-shaped room with black walls, floor,\n" +
    "and ceiling. It is very plain, though there is a large sign\n" +
    "on the wall.\n";

  dest_dir = ({
    PATH + "rooms/lounge", "south",
  });

  items = ({
    "room", "A starkly-furnished black room",
    "walls", "Plain black walls; there is a sign on one of them",
    "floor", "A black floor made of stone",
    "ceiling", "A black ceiling",
    "wall", "There is a sign on it",
    "sign", "You can probably read it",
  });
}

init() {
  ::init();
  add_action("read", "read");
  add_action("buy", "buy");
}

read(arg) {
  if(arg == "sign" || arg == "large sign") {
    write("You read the sign. It says:\n");
    write("    This is the room that houses the mighty Prism of Elements.\n");
    write("Here you can open a conduit and transfer Power from the Prism\n");
    write("into your Brooch. The cost is " + COST + " coins per point.\n");
    write("To buy Power, type \"buy <number>\".\n");
    write("To buy maximum power, type \"buy max\".\n");
    return 1;
  }
}

buy(arg) {
  int amount, diff;
  object brooch;
  brooch = present("guildbrooch", TP);
  if(brooch) {
    diff = brooch->query_max_bp() - brooch->query_bp();
    if(diff == 0) {
      write("Your Brooch is already full.\n");
      return 1;
    }
    if(arg == "max") {
      if(diff <= TP->query_money() / COST) command("buy " + diff, TP);
      else command("buy " + (TP->query_money() / COST), TP);
      return 1;
    }
    if(arg && sscanf(arg, "%d", amount)) {
      if(amount <= 0) {
	write("You may only buy a positive amount.\n");
	return 1;
      }
      if(amount > TP->query_money() / COST) {
	write("You do not have enough money.\n");
	return 1;
      }
      if(amount > diff) amount = diff;
      TP->add_money( - (amount * COST));
      brooch->add_bp(amount);
      write("You buy " + amount + " units of power for your Brooch.\n");
      say(TP->NAME + " buys power for " + TP->POS + " Brooch.\n");
      return 1;
    }
    write("Buy what?\n");
    return 1;
  }
}
