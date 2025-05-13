#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
string w_name,alt_name;
int i,class,value,weight,type;
object orc, wp;

  if (!present("ogre"))
     for (i=0;i<3;i++) {
	orc=clone_object("obj/monster");
	orc->set_name("ogre");
	orc->set_race("ogre");
	orc->set_level(random(15)+1);
	orc->set_al(-500);
	orc->set_aggressive(1);
	orc->set_move_at_reset(1);
	switch (random(3)) {
	case 0 : w_name="club"; class=10; value=50; weight=3; type=1; break;
	case 1 : w_name="small morningstar"; class=12; value=100; weight=4; type=1; alt_name="morningstar"; break;
case 2 : w_name="wooden club";class=9; value=50; weight=3; type=1; alt_name="club"; break;
	}
	wp=clone_object("obj/weapon");
	wp->set_name(w_name);
	wp->set_class(class);
	wp->set_value(value);
	wp->set_weight(weight);
	wp->set_alt_name(alt_name);
        wp->set_type(type);

	move_object(orc,this_object());
	move_object(wp,orc);
	command("wield "+w_name,orc);
     }
}

TWO_EXIT("players/herp/orc/v3","south",
	 "players/herp/orc/u4","west",
	 "The orc valley",
	 "You are in the orc valley. This is the place where one of their\n" +
	 "allies are.\n",1)
