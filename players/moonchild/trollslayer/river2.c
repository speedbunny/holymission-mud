#include "room.h"

THREE_EXIT("players/moonchild/trollslayer/path1", "east",
	"players/moonchild/trollslayer/river1", "south",
	"room/plane9", "up",
	"River bank",
	"You are standing underneath a soft grassy bank, beside a fast-flowing river\n" +
	"which springs from a hole in the ground. To the south the river seems to\n" +
	"broaden into an attractive little lake. A path leads off to the east.\n", 1)

init() {
  ::init();
  add_action("drink", "drink");
}

id(str) { return str=="lake" || str=="bank" || str=="hole" || str=="river"; }

long(str) {
  if(str=="lake") {
    write("A pretty little lake, complete with lily-pad and frogs.\n");
    return 1;
  }
  if(str=="bank") {
    write("A soft grassy bank.\n");
    return 1;
  }
  if(str=="hole") {
    write("Water pours out of this hole in the ground. There is so much water coming\n"
	+ "out that there is no way you could possibly clamber into the hole.\n");
    return 1;
  }
  if(str=="river") {
    write("A fast-flowing river with black-looking water.\n");
    return 1;
  }
  ::long();
}

drink(str) {
  if(str!="water" && str!="from river") return;
  write("You drink some water. It tastes absolutely vile - it's probably poisoned!\n");
  this_player()->add_poison(2);
  say(this_player()->query_name() + " drinks some water.\n");
  return 1;
}
