#include "room.h";

object stone;
int stones;

ONE_EXIT("players/moonchild/trollslayer/ruinpath", "south",
	"In a ruined building",
	"You are standing inside the ruin of an old, roofless farm building. The\n"
	+ "crumbling walls surround you; although they are weak they prevent any exit\n"
	+ "other than the way you came in.\n", 1)

#undef EXTRA_RESET
#define EXTRA_RESET\
  stones=0

init() {
  ::init();
  add_action("loosen", "loosen");
}

id(str) { return str=="building" || str=="farm building" || str=="wall" || str=="walls" || str=="ruin"; }

long(str) {
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
