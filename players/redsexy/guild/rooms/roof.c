inherit "room/room";

#include "/players/redsexy/guild/guilddefs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  property = "no_teleport";
  short_desc = "Roof";
  long_desc =
    "    You find yourself on the flat roof of the Summoners' Guild,\n" +
    "and brace yourself against the frigid winds blowing mightily\n" +
    "over the surrounding landscape, an icy mass of craggy rock at\n" +
    "the top of the mountain.\n" +
    "    A black stone staircase winds down into the building proper.\n";
  no_obvious_msg = "";

  items = ({
    "roof", "A black-robed, hooded figure watching you intently",
    "landscape", "A bitterly cold scene covered in ice and snow",
    "rock", "The jagged rock of the mountain top",
    "mountain", "The Guild sits on top of one of the higher peaks",
    "staircase", "A black spiral staircase leading down",
    "building", "The Summoners Guild, upon which you now stand",
    "guild", "The Guild of Summoners",
  });
}

init() {
  ::init();
  add_action("climb", "climb");
  add_action("down", "down");
}

climb(arg) {
  if(arg == "stairs" || arg == "staircase" ||
     arg == "down") {
    write("You climb down the staircase.\n");
    TP->MOVEP("down the staircase#" + PATH + "rooms/anteroom");
    return 1;
  }
  write("Climb what?\n");
  return 1;
}

down(arg) {
  if(!arg) {
    write("You climb down the stairs.\n");
    TP->MOVEP("down the staircase#" + PATH + "rooms/anteroom");
    return 1;
  }
}
