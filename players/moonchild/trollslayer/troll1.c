#include "room.h"

object troll;

#undef EXTRA_RESET
#define EXTRA_RESET\
  extra_reset();

extra_reset() {
  if(!troll) {
    troll=clone_object("obj/monster");
    troll->set_name("troll");
    troll->set_short("A troll");
    troll->set_long("A vicious-looking troll.\n");
    troll->set_level(10);
    troll->set_aggressive(1);
    troll->set_al(-150);
    troll->set_wc(20);
    troll->add_money(50+random(151));
    move_object(troll, this_object());
  }
}

TWO_EXIT("room/forest1", "north",
	"players/moonchild/trollslayer/troll2", "south",
	"Troll path",
	"You are walking along the path to the troll village. The animals all look\n"
	+ "very nervous, probably because of the large number of trolls around here.\n", 1)
