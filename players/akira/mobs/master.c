inherit "players/trout/mobs/guard_help";
#include "/players/trout/defs.h"

reset(arg){
	::reset(arg);
	if(arg) return;
         set_name("Psi-Master");
        set_long("This is one of the teachers of the tower, also known as\n"+
                 "as a Psi-Master. They were red robes to show that they\n"+
                 "have reached the rank of Master. He does not look like\n"+
                 "a very strong man, but do not let this fool you, his mind\n"+
                 "is all he will need to kill you.\n");
        set_alias("master");
        set_level(30+random(5));
	set_race("human");
	set_gender(1);
	GP(2000);
	set_number_of_arms(2);
        set_wc(15);
	set_ac(6);
	}
hit_player(dam){
	switch(RAN(100)){
			case 0..20:
				  TP()->HIT(50);
write("The Master hits you with a powerful Mind Bolt!\n");
TLR( ENV(), "The Master looks "+TPN+" in the eye!\n");
				  break;
			default: break;
                       case 21..30:
                                  TP()->add_poison(40);
write("The Master reaches out to your mind, and makes your blood boil!\n");
TLR( ENV(), "The Master focuses on "+TPN+" with his mind!\n");
                                  break;
			}
	return:: hit_player(dam);
	}
