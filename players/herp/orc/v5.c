#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

string chats;

get_chats() {

   if (!chats) {
	chats=allocate(4);
	chats[0]="Huge orc says: Halt! Intruder!\n";
	chats[1]="Huge orc says: Kill him quick and dirty.\n";
	chats[2]="Huge orc says: Where are our allies ?!\n";
    }
    return chats;
}

extra_reset() {
string w_name,alt_name;
int i,class,value,weight,type;
object orc, wp;

  if (!present("orc"))
     for (i=0;i<5;i++) {
	orc=clone_object("obj/monster");
	orc->set_name("huge orc");
	orc->set_race("orc");
	orc->set_level(random(15)+1);
	orc->set_ac(25);
	orc->set_al(-1000);
	orc->set_aggressive(1);
	orc->set_move_at_reset(1);
	switch (random(4)) {
	case 0 : w_name="battleaxe"; class=12; value=100; weight=3; alt_name="axe"; break;
	case 1 : w_name="waraxe";    class=14; value=200; weight=4; alt_name="axe"; break;
	case 2 : w_name="axe";class=9; value=25; weight=2; break;
	case 3 : w_name="small morningstar";class=12;value=150; weight=6; alt_name="morningstar"; break;
	}
	wp=clone_object("obj/weapon");
	wp->set_name(w_name);
        wp->set_weight(weight);
	wp->set_class(class);
	wp->set_value(value);
	wp->set_alt_name(alt_name);

	move_object(orc,this_object());
	move_object(wp,orc);
	command("wield "+w_name,orc);
     }
}

TWO_EXIT("players/herp/orc/v6","west",
	 "players/herp/orc/v4","east",
	 "The orc valley",
	 "You are in the orc valley. This place is inhabitated by orcs.\n" +
	 "Your nose is tortured by the strong smell of orc urine.\n",1) 
