inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(0);
  short_desc = "Black Fountain";
  long_desc =
    "    The first thing you notice here, aside from the darkness,\n" +
    "is the large fountain standing before you. A clearing surrounds\n" +
    "it, and other than the sounds of the fountain's water the place\n" +
    "is silent.\n";

  dest_dir = ({
    NWFORESTA + "rooms/a19", "northeast",
  });

  items = ({
    "fountain", "A black stone fountain spouting murky water",
    "water", "Thick, dark water splashing forth from the fountain",
    "clearing", "A dense ring of trees surrounding an open space",
  });
}

init() {
  ::init();
  add_action("drink", "drink");
}

drink(arg) {
  if(arg == "water" || arg == "water from fountain" ||
     arg == "dark water" || arg == "brown water") {
    write("Your mouth touches the water and burns with pain!\n");
    say(TP->NAME + " drinks some water, and staggers backwards in pain!\n");
    TP->ADDHP(-15);
    return 1;
  }
}

fill_it(obj) {
  write("Your hands burn as you fill your prism with the liquid.\n");
  write("It bubbles and fizzes, trapped within the confines of the prism.\n");
  say(TP->NAME + " fills " + TP->POS + " prism with some water.\n");
  obj->set_type("brown");
  obj->set_value(2000);
  obj->set_extra("It is filled with a bubbling brown liquid.\n");
  obj->set_inscr("smash");
  obj->set_msg("The air is suddenly filled with a spray of acid!\n");
  return 1;
}

query_fill_with() { return "water"; }
