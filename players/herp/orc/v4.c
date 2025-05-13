#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

string chats;

get_chats() {

   if (!chats) {
	chats=allocate(4);
	chats[0]="Large orc says: Halt! Intruder!\n";
	chats[1]="Large orc says: Kill him quick and dirty.\n";
	chats[2]="Large orc says: Where are our allies ?!\n";
	chats[3]="Large orc says: Not again ... I'm fed up with them.\n";
    }
    return chats;
}

extra_reset() {
string w_name,alt_name;
int i,class,value,weight,type;
object orc, wp;

  if (!present("orc"))
     for (i=0;i<10;i++) {
	orc=clone_object("obj/monster");
	orc->set_name("large orc");
	orc->set_race("orc");
	orc->set_level(random(15)+1);
	orc->set_al(-60);
	orc->set_aggressive(1);
	orc->set_move_at_reset(1);
	orc->load_a_chat(50,get_chats());
	switch (random(4)) {
	case 0 : w_name="battleaxe"; class=12; value=100; weight=3; type=1;alt_name="axe"; break;
	case 1 : w_name="waraxe";    class=14; value=200; weight=4; type=1;alt_name="axe"; break;
	case 2 : w_name="axe";class=9; value=25; weight=1; type=1;break;
	case 3 : w_name="small morningstar";class=12;value=150; weight=5; type=1;alt_name="morningstar"; break;
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

THREE_EXIT("players/herp/orc/u4","north",
	 "players/herp/orc/v5","west",
	 "players/herp/orc/v3","east",
	 "The orc valley",
	 "You are in the orc valley. This place is inhabitated by orcs.\n" +
	 "Your nose is tortured by the strong smell of orc urine.\n",1) 
