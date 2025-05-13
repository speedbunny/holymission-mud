inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Blue Pool";
  long_desc =
    "    Here the sunlight filters down and glimmers off the surface\n" +
    "of a pool of shimmering blue water. The water looks fresh and\n" +
    "pure; you guess that it bubbles up from an underground spring.\n" +
    "The plants here look extremely vital and alive, well-fed by the\n" +
    "nourishing pool.\n";

  dest_dir = ({
    NWFORESTB + "rooms/b10", "east",
  });

  items = ({
    "sunlight", "Dazzling patterns of light reflect off of the water",
    "pool", "A pool of clear blue water",
    "water", "The water looks cold and delicious",
    "plants", "Bright green plants of all varieties",
  });
}

init() {
  ::init();
  add_action("drink", "drink");
}

drink(arg) {
  if(arg == "water" || arg == "from pool") {
    write("You drink deeply from the pool. You feel refreshed.\n");
    say(TP->NAME + " drinks from the pool.\n" );
    return 1;
  }
}

fill_it(obj) {
  write("You fill the empty prism with cool blue water.\n");
  say(TP->NAME + " fills " + TP->POS + " prism with water.\n");
  obj->set_type("blue");
  obj->set_value(2000);
  obj->set_extra("It is filled with a clear liquid with a bluish tinge.\n");
  obj->set_inscr("smash");
  obj->set_msg("A cool gentle rain falls for a moment.\n");
  return 1;
}

query_fill_with() { return "water"; }
