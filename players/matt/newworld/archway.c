#include "/players/matt/defs.h"

id(arg) {
  return arg == "gate" || arg == "arch" || arg == "archway";
}
short() { return "A black marble Archway"; }
long() {
  write("    This is a large Arch standing by itself on the ground.\n");
  write("Made of shiny black marble, the Arch towers above you and\n");
  write("seems to have a magical aura about it. You find it strange\n");
  write("that someone would put up such a structure here, as you could\n");
  write("walk right through it and not get anywhere.\n");
}
init() {
  add_action("enter", "enter");
}

int no_clean_up() {
    return 1;
}

enter(arg) {
  if(id(arg)) {
    write("You enter the Gate.\n");
    TP->MOVEP("through the Gate and vanishes#" +
	      NEWWORLD + "entry");
    return 1;
  }
  write("Enter what?\n");
  return 1;
}
