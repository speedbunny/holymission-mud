#include "room.h"

object stone;
int stones;

THREE_EXIT("players/moonchild/trollslayer/ruin", "north",
	"players/moonchild/trollslayer/path4", "east",
	"players/moonchild/trollslayer/bycave", "west",
	"By a ruined building",
	"You are standing beside the ruin of an old, roofless farm building. A path\n"
	+ "leads east-west through here; the entrance to the building is to the north.\n", 1)

#undef EXTRA_RESET
#define EXTRA_RESET\
  stones=0

init() {
  ::init();
  add_action("loosen", "loosen");
}

id(str) { return str=="building" || str=="farm building" || str=="wall" || str=="walls" || str=="ruin" || str=="path"; }

long(str) {
  if(str=="path") {
    write("A small winding country path.\n");
    return 1;
  }
  if(id(str)) {
    if(str=="walls") str="wall";
    if(stones<4) {
      write("This " + str + " looks in a very poor state. Some of the\n" +
      "stones that make it up look as if you could loosen them.\n");
    }
    else write("This " + str + " looks in a very poor state.\n");
    return;
  }
  ::long();
}

loosen(str) {
  if(str=="stone" || str=="stones") {
    if(stones<4) {
      stones++;
      move_object(stone=clone_object("obj/treasure"),this_object());
      stone->set_id("stone");
      stone->set_short("A big grey stone");
      stone->set_long("This is a big grey stone, probably taken out of some old building.\n");
      stone->set_value(2);
      stone->set_weight(20);
      write("You loosen a stone from the building. It rolls along the ground.\n");
      say(this_player()->query_name() + " loosens a stone from the building.\nIt rolls along the ground.\n");
      return 1;
    }
    else {
      write("There don't seem to be any more stones loose.\n");
      return 1;
    }
  }
  write("Loosen what?\n");
  return 1;
}
