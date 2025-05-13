inherit "/room/room";

#include "/players/matt/defs.h"

object dragon;

reset(arg) {
  if(!dragon) {
    dragon = clone_object(NWFORESTA + "monsters/mistdragon");
    MOVE(dragon, TO);
  }
  if(arg) return;
  set_light(0);
  short_desc = "Mist";
  long_desc =
    "    You stand in the midst of a shroud of cold whiteness. Your\n" +
    "entire conception of space is confused, as you can see less than\n" +
    "a meter in front of your face. You sense a dark Presence nearby.\n";

  items = ({
    "whiteness", "A hissing white mist that envelops you",
  });
}

init() {
  ::init();
  add_action("leave", "exit");
  add_action("leave", "leave");
  add_action("mist", "south");
}

leave(arg) {
  if(!arg || arg == "mist") {
    mist();
    return 1;
  }
  write("Exit what?\n");
  return 1;
}

mist() {
  write("You find your way back through the misty curtain.\n");
  TP->MOVEP("though the misty curtain#" + NWFORESTA + "rooms/a08");
  return 1;
}

fill_it(obj) {
  write("You fill the prism with some white mist.\n");
  write("The mist writhes as though it were alive.\n");
  say(TP->NAME + " fills " + TP->POS + " prism with mist.\n");
  obj->set_type("white");
  obj->set_value(2000);
  obj->set_extra("It is filled with white mist.\n");
  obj->set_inscr("smash");
  obj->set_msg("The mist hisses as it escapes from the prism.\n");
  return 1;
}

query_fill_with() { return "mist"; }
