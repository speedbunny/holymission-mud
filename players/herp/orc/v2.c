#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

string chats;

get_chats() {

   if (!chats) {
	chats=allocate(6);
	chats[0]="Orc says: Now look at this disgusting adventurer!\n";
	chats[1]="Orc farts right into your face.\n";
	chats[2]="Orc says: Ash! Lugburz, ghaan Kuttln!\n";
	chats[3]="Orc sniffs in your direction.\n";
	chats[4]="Orc says: This one makes me vomit.\n";
	chats[5]="Orc pukes on your shirt.\n";
    }
    return chats;
}

extra_reset() {
string w_name,alt_name;
int i,class,value,weight,type,th;
object orc, wp;

  if (!present("orc"))
     for (i=0;i<2;i++) {
	orc=clone_object("obj/monster");
	orc->set_name("orc");
	orc->set_race("orc");
	orc->set_level(random(5)+6);
	orc->set_al(-60);
	orc->set_aggressive(1);
	orc->set_move_at_reset(1);
	orc->load_a_chat(50,get_chats());
        th=0;
	switch (random(5)) {
	case 0 : w_name="knife";    class=5; value=8;  weight=1; type=2; break;
	case 1 : w_name="knife";    class=7; value=15; weight=1; type=2; break;
	case 2 : w_name="hand axe"; class=9; value=25; weight=2; type=1; alt_name="axe"; break;
	case 3 : w_name="spear";    class=10; value=50; weight=1; type=2; th=1; break;
	case 4 : w_name="large spear";class=14; value=300; weight=3; type=0; th=1; alt_name="spear"; break;
	}
	wp=clone_object("obj/weapon");
	wp->set_name(w_name);
	wp->set_class(class);
	wp->set_value(value);
	wp->set_weight(weight);
	wp->set_alt_name(alt_name);
        wp->set_type(type);
        if(th) wp->set_two_handed();

	move_object(orc,this_object());
	move_object(wp,orc);
	command("wield "+w_name,orc);
     }
}

TWO_EXIT("players/herp/orc/v3","west",
	 "players/herp/orc/v11","east",
	 "The orc valley",
	 "You are in the orc valley. This place is inhabitated by orcs.\n" +
	 "Your nose is tortured by the strong smell of orc urine.\n",1) 
