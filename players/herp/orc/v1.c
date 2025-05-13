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
int i,class,value,weight,type;
object orc, wp;

  if (!present("orc"))
     for (i=0;i<7;i++) {
	orc=clone_object("obj/monster");
	orc->set_name("orc");
	orc->set_race("orc");
	orc->set_level(random(3)+1);
	orc->set_hp(50);
	orc->set_ep(2000);
	orc->set_al(-360);
	orc->set_aggressive(1);
	orc->set_move_at_reset(1);
	orc->load_a_chat(50,get_chats());
	switch (random(4)) {
	case 0 : w_name="knife";    class=5; value=8;  weight=1; type=2; break;
	case 1 : w_name="knife";    class=7; value=15; weight=1; type=2; break;
	case 2 : w_name="hand axe"; class=9; value=25; weight=2; type=1; alt_name="axe"; break;
	case 3 : w_name="spear";    class=10; value=50; weight=1; type=2; break;
	}
	wp=clone_object("obj/weapon");
	wp->set_name(w_name);
	wp->set_class(class);
	wp->set_value(value);
	wp->set_weight(weight);
	wp->set_alt_name(alt_name);
        wp->set_type(type);
        if(w_name=="spear") wp->set_two_handed();

	move_object(orc,this_object());
	move_object(wp,orc);
	command("wield "+w_name,orc);
     }
}

THREE_EXIT("/players/saffrin/area/pk/room/v1","south",
          "/players/herp/orc/v11","west",
	 "players/herp/orc/v0","east",
	 "The orc fireplace",
	 "You are in the orc valley.\n"+
	 "It seems that here some of them orcs must have made camp.\n" +
	 "You can see limbs laying strewn about.\n",1)
