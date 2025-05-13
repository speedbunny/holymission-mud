#include "room.h"

ONE_EXIT("players/moonchild/trollslayer/river2", "north",
	"By the lake",
	"You are standing by an attractive little lake, complete with lily-pads and\n" +
	"frogs, fed by a river coming from the north. It is very peaceful here and\n" +
	"the sun is shining.\n", 1)

init() {
  ::init();
  add_action("swim", "swim");
  add_action("enter", "enter");
  add_action("dive", "dive");
  add_action("drink", "drink");
}

id(str) { return str=="lake" || str=="lilypads" || str=="lily-pads" || str=="river" || str=="frogs"; }

enter(str) { if(str=="lake") return swim(); }

dive() {
  write("You dive into the lake.\n");
  return !this_player()->move_player(", diving into the lake#players/moonchild/puzzle/lake_bottom");
}

swim() {
  write("You swim off into the lake.\n");
  this_player()->move_player("into the lake#players/moonchild/trollslayer/lake");
  return 1;
}

drink() {
  write("You drink some water. It has a rather thin taste to it.\n");
  say(this_player()->query_name() + " drinks some water.\n");
  return 1;
}

long(str) {
  if(str=="lake") {
    write("A pretty little lake, complete with lily-pads and frogs.\n");
    return 1;
  }
  if(str=="river") {
    write("This lake is fed by an attractive little river.\n");
    return 1;
  }
  if(str=="frogs") {
    write("There might well be some frogs on the lake.\n");
    return 1;
  }
  if(id(str)) {
    write("There are a lot of lily-pads on the lake.\n");
    return 1;
  }
  ::long();
}
