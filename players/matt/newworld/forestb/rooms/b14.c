inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Dead End";
  long_desc =
    "    You have come to a dead end. In all directions but west, the\n" +
    "trees are far too thick to pass between; they stand very close\n" +
    "to one another, straight and proud, except one which looks as\n" +
    "though it has been struck down by a bolt of lightning. Its trunk\n" +
    "is charred and split, and blackened branches hang low from its\n" +
    "splintered body.\n";

  dest_dir = ({
    NWFORESTB + "rooms/b11", "west",
  });

  items = ({
    "trees", "All the trees are tall and healthy save one",
    "tree", "A single tree is black and lifeless",
    "trunk", "As you look more closely you can see a narrow crack in it",
    "branches", "In contrast to the others, these hang down low",
    "crack", "A crack gouged out by the lightning",
  });
}

init() {
  ::init();
  add_action("enter", "enter");
}

enter(arg) {
  if(arg == "crack" || arg == "narrow crack") {
    if(TP->query_size() == 1) {
      write("You manage to barely squeeze through the narrow crack.\n");
      TP->MOVEP("through the crack#" + NWFORESTB + "rooms/crack");
      return 1;
    }
    write("The crack is too narrow for you to squeeze through.\n" );
    return 1;
  }
  write("Enter what?\n");
  return 1;
}
