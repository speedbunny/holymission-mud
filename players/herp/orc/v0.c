#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

string chats;

get_chats() {

   if (!chats) {
	chats=allocate(5);
	chats[0]="Orc says: Yummy, here comes a little snack !\n";
	chats[1]="Orc says: Tell Shaggratt to heat the oven !\n";
	chats[2]="Orc says: Get lost, crap !\n";
	chats[3]="Orc says: Shall we eat him raw ?\n";
	chats[4]="Orc says: Bah, I don't like it when the food smells this way.\n";
    }
    return chats;
}

TWO_EXIT("players/herp/orc/v1","west",
	 "room/orc_vall","east",
	 "The orc valley",
	 "You are in the orc valley. This place is inhabited by orcs.\n" +
	 "You can hardly breathe.\n",1)

extra_reset() {
string w_name,alt_name;
int i,class,value,weight,type;
object orc, wp;

  if (!present("orc"))
     for (i=0;i<5;i++) {
	orc=clone_object("obj/monster");
	orc->set_name("orc");
	orc->set_race("orc");
	orc->set_level(random(3)+1);
	orc->set_hp(50);
	orc->set_ep(2000);
	orc->set_al(-60);
	orc->set_aggressive(1);
	orc->set_move_at_reset(1);
	orc->load_a_chat(50,get_chats());
	switch (random(3)) {
	case 0 : w_name="knife";    class=5; value=8;  weight=1; type=2; break;
	case 1 : w_name="knife";    class=7; value=15; weight=1; type=2; break;
	case 2 : w_name="hand axe"; class=9; value=25; weight=2; alt_name="axe"; type=1; break;
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
