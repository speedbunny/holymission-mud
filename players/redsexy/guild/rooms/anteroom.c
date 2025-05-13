inherit "room/room";

#include "/players/redsexy/guild/guilddefs.h"

object guard;

reset(arg) {
  if(!guard) {
    guard = clone_object(PATH + "creatures/guardian");
    MOVE(guard, TO);
  }
  if(arg) return;
  set_light(1);
  short_desc = "Dim Room";
  long_desc =
    "    This is a plain, dimly-lit room. Somehow, the fierce, biting\n" +
    "winds do not enter through the open doorway leading outside.\n" +
    "    A black stone staircase is visible in the northwest corner,\n" +
    "winding upwards and downwards.\n";
  no_obvious_msg = "";

  items = ({
    "staircase", "A spiral staircase leading up and down",
    "stairs", "A winding staircase",
  });
}

init() {
  ::init();
  add_action("up", "up");
  add_action("down", "down");  
  add_action("climb", "climb");
  add_action("enter", "enter");
}

up(arg) {
  if(!arg) climb("up");
  else return;
  return 1;
}

down(arg) {
  if(!arg) climb("down");
  else return;
  return 1;
}

climb(arg) {
  if(arg == "stairs" || arg == "staircase") {
    write("You can climb either up or down.\n");
    return 1;
  }
  if(arg == "up") {
    if(TP->query_guild() == SUMM || TP->query_immortal()) {
      write("You climb up the staircase.\n");
      TP->MOVEP("up the staircase#" + PATH + "rooms/roof");
      return 1;
    }
    write("The Guardian hisses: Only the Masters may pass!\n");
    return 1;
  }
  if(arg == "down") {
    if(TP->query_guild() == SUMM || TP->LEVEL <= 10 ||
       TP->query_immortal()) {
      write("You climb down the staircase.\n");
      TP->MOVEP("down the staircase#" + PATH + "room");
      return 1;
    }
    write("The Guardian hisses: Only the Masters may pass!\n");
    return 1;
  }
  write("Climb what?\n");
  return 1;
}

enter(arg) {
  if(arg == "door" || arg == "doorway") {
    write("You enter the doorway.\n");
    TP->MOVEP("through the doorway#" + "players/redsexy/guild/rooms/circle");
    return 1;
  }
  write("Enter what?\n");
  return 1;
}
