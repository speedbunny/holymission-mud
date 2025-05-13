#include "room.h"

object troll,troll2;

#undef EXTRA_RESET
#define EXTRA_RESET\
  extra_reset();

extra_reset() {
  if(!troll) {
    object armour;
    armour=clone_object("obj/armour");
    armour->set_name("armour");
    armour->set_alias("leather armour");
    armour->set_value(110);
    armour->set_short("A leather armour");
    armour->set_weight(3);
    armour->set_ac(3);
    troll=clone_object("obj/monster");
    troll->set_name("troll");
    move_object(armour, troll);
    troll->init_command("wear armour");
    troll->set_short("A troll");
    troll->set_long("An evil-looking troll.\n");
    troll->set_level(11);
    troll->set_al(-200);
    troll->set_aggressive(1);
    troll->set_wc(22);
    move_object(troll,this_object());
  }
  if(!troll2) {
    object dagger;
    dagger=clone_object("obj/weapon");
    dagger->set_name("dagger");
    dagger->set_value(100);
    dagger->set_class(10);
    dagger->set_weight(2);
    dagger->set_short("A trollish dagger");
    dagger->set_long("A bloodstained dagger, formerly the property of a now deceased troll.\n");
    troll2=clone_object("obj/monster");
    troll2->set_name("troll");
    move_object(dagger,troll2);
    troll2->init_command("wield dagger");
    troll2->set_short("A troll");
    troll2->set_long("A nasty-looking troll.\n");
    troll2->set_level(11);
    troll2->set_al(-200);
    troll2->set_aggressive(1);
    troll2->set_wc(22);
    move_object(troll2, this_object());
  }
}

TWO_EXIT("players/moonchild/trollslayer/troll1", "north",
	"players/moonchild/trollslayer/troll3", "south",
	"Troll path",
	"You are walking along the path to the troll village. The animals all look\n"
	+ "very nervous, probably because of the large number of trolls around here.\n"
	+ "To the south you can see some huts, probably of trollish origin.\n", 1)
