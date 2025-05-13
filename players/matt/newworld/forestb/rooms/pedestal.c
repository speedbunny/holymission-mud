inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Stone Pedestal";
  long_desc =
    "    The top of the pedestal is merely a smooth, near-perfect\n" +
    "circle of solid stone, about six meters in diameter. You can\n" +
    "literally feel waves of power pulsating through the air,\n" +
    "radiating out from the pedestal.\n" +
    "    You are surprisingly high up; many treetops are visible\n" +
    "below you.\n";

  items = ({
    "pedestal", "A circular column of stone",
    "stone", "Heavy-looking solid stone; you cannot tell what kind",
    "treetops", "The treetops of the Eastern Forest",
  });
}

init() {
  ::init();
  add_action("climb", "climb");
  add_action("draw", "draw");
  add_action("summon", "summon");
}

climb(arg) {
  if(arg == "pedestal" || arg ==  "stone pedestal" ||
     arg == "down pedestal" || arg == "down") {
    write("You climb down the stone pedestal.\n");
    TP->MOVEP("down the stone pedestal#" + NWFORESTB + "rooms/b19");
    return 1;
  }
  write("Climb what?\n");
  return 1;
}
