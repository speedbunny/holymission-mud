#include "room.h"

object troll,troll2,troll3;

#undef EXTRA_RESET
#define EXTRA_RESET\
  extra_reset();

extra_reset() {
  if(!troll) {
    object armour;
    armour=clone_object("obj/armour");
    armour->set_name("platemail");
    armour->set_value(500);
    armour->set_short("Some trollish platemail");
    armour->set_weight(4);
    armour->set_ac(4);
    troll=clone_object("obj/monster");
    troll->set_name("troll");
    move_object(armour, troll);
    troll->init_command("wear platemail");
    troll->set_short("A troll");
    troll->set_long("A horrible-looking troll.\n");
    troll->set_level(13);
    troll->set_al(-250);
    troll->set_aggressive(1);
    troll->set_wc(26);
    move_object(troll,this_object());
  }
  if(!troll2) {
    object pike;
    pike=clone_object("obj/weapon");
    pike->set_name("pike");
    pike->set_value(750);
    pike->set_class(14);
    pike->set_weight(3);
    pike->set_short("A huge great pike");
    pike->set_long("An enormous great pike. It looks like it is a pretty powerful weapon.\n");
    troll2=clone_object("obj/monster");
    troll2->set_name("troll");
    move_object(pike,troll2);
    troll2->init_command("wield pike");
    troll2->set_short("A troll");
    troll2->set_long("A disgusting-looking troll.\n");
    troll2->set_level(13);
    troll2->set_al(-250);
    troll2->set_aggressive(1);
    troll2->set_wc(26);
    move_object(troll2, this_object());
  }
  if(!troll3) {
    object diamond;
    diamond=clone_object("obj/treasure");
    diamond->set_id("diamond");
    diamond->set_value(200+random(301));
    diamond->set_weight(1);
    troll3=clone_object("obj/monster");
    troll3->set_name("troll");
    move_object(diamond,troll3);
    troll3->set_short("A troll");
    troll3->set_long("A powerful-looking troll.\n");
    troll3->set_level(13);
    troll3->set_al(-250);
    troll3->set_aggressive(1);
    troll3->set_wc(26);
    move_object(troll3, this_object());
  }
}

FOUR_EXIT("players/moonchild/trollslayer/troll2", "north",
	"players/moonchild/trollslayer/easthut", "east",
	"players/moonchild/trollslayer/trollking", "south",
	"players/moonchild/trollslayer/westhut", "west",
	"Troll village",
	"You are standing in the centre of the troll village. There are huts to the\n"
	+ "east and west, and a larger building to the south. A road leads off north.\n", 1)

init() {
  ::init();
  add_action("south", "south");
}

south() {
  if(present("troll")) {
    tell_room(this_object(),"Troll says: You may not pass.\n");
    return 1;
  }
  this_player()->move_player("south#players/moonchild/trollslayer/trollking");
  return 1;
}
