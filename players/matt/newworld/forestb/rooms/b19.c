inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Large Clearing";
  long_desc =
    "    If the forest path were still fully intact, this place\n" +
    "would be a crossroads of sorts; however, it is now just a\n" +
    "large clearing. The trees stand in a silent circle around\n" +
    "you, almost protectively, though there are rather wide\n" +
    "openings allowing passage in all four compass directions.\n" +
    "    In the center of this grove sits a grey stone pedestal;\n" +
    "you sense a tremendous energy radiating out from it.\n";

  dest_dir = ({
    NWFORESTB + "rooms/b22", "east",
    NWFORESTB + "rooms/b17", "west",
    NWFORESTB + "rooms/b18", "north",
    NWFORESTB + "rooms/b20", "south",
  });

  items = ({
    "clearing", "A large, circular clearing",
    "trees", "Thick-trunked trees keeping watch over this place",
    "openings", "These are openings wide enough for you to pass through",
    "pedestal", "A tall circular pedestal with grooves in its side",
    "grooves", "They look like footholds to climb the pedestal",
  });
}

init() {
  ::init();
  add_action("climb", "climb");
}

climb(arg) {
  if(arg == "pedestal" || arg == "stone pedestal" ||
     arg == "up pedestal" || arg == "up") {
    write("You climb the smooth stone pedestal.\n");
    TP->MOVEP("up the stone pedestal#" + NWFORESTB + "rooms/pedestal");
    return 1;
  }
  write("Climb what?\n");
  return 1;
}

