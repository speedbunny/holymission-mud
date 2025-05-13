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
int i,class,value,weight,type,th;
object orc, wp;

  if (!present("orc"))
     for (i=0;i<2;i++) {
	orc=clone_object("obj/monster");
	orc->set_name("huge orc");
	orc->set_race("orc");
	orc->set_level(random(20)+16);
	orc->set_ac(35);
	orc->set_wc(25);
	orc->set_al(-1000);
	orc->set_aggressive(1);
	orc->set_move_at_reset(1);
	move_object(orc,this_object());
        th=0;
        switch(random(9)) {
            case 0: w_name="bloodaxe"; class=20; value=3500; weight=10; alt_name="axe";type=1; break;
            case 1: w_name="morningstar"; class=15; value=500; weight=6; alt_name="morningstar";type=1; break;
            case 2: w_name="heavy morningstar"; class=18; value=2000; weight=8; alt_name="morningstar";type=1; break;
            case 3: w_name="huge pike"; class=18; value=2000; weight=6; alt_name="pike";type=2; th=1; break;
            case 4: w_name="falchion"; class=18; value=2000; weight=6; alt_name="pike";type=0; break;
            case 5: w_name="heavy wooden club"; class=19; value=2000; weight=10; alt_name="club";type=1; th=1;break;
            default: w_name="nix";
        }
        if(w_name!="nix") {
	    wp=clone_object("obj/weapon");
	    wp->set_name(w_name);
	    wp->set_class(class);
	    wp->set_value(value);
	    wp->set_weight(weight);
	    wp->set_alt_name(alt_name);
            wp->set_type(type);
            if(th) wp->set_two_handed();
        
	    move_object(wp,orc);
	    command("wield "+w_name,orc);
        }
    }
}

TWO_EXIT("players/herp/orc/v5","east",
	 "players/moonchild/pot/orc1","west",
	 "The orc valley",
	 "You are in the orc valley. This place is inhabitated by orcs.\n" +
	 "Your nose is tortured by the strong smell of orc urine.\n",1) 
