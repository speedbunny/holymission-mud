inherit "players/trout/mobs/guard_help";
#include "/players/trout/defs.h"

reset(arg){
	::reset(arg);
	if(arg) return;
         set_name("Psi-Lord Zorak");
        set_long("This is Zorak, Psi-Lord of the Tower of Highest Thought.\n"+
                 "Just standing near him you can feel the power of his\n"+
                 "mind filling the room. He is a master of mental combat.\n"+
                  "Zorak wears the black and gold robes of a Psi-lord. For\n"+
                 "some strange reason you do not think it would be wise to\n"+
                 "try to attack him.\n");
        set_alt_name("zorak");
        set_level(50);
	set_race("human");
	set_gender(1);
        GP(10000);
	set_number_of_arms(2);
        set_wc(15);
        set_ac(20);
	}
hit_player(dam){
	switch(RAN(100)){
			case 0..20:
				  TP()->HIT(50);
write("Zorak hits you with a powerful Mindbolt!\n");
TLR( ENV(), "Zorak looks deep into "+TPN+"'s eyes!\n");
				  break;
			default: break;
                       case 21..30:
                                  TP()->add_poison(40);
write("Zorak reaches out to your mind, and makes your blood start to boil!\n");
TLR( ENV(), "Zorak focuses on "+TPN+" with his mind!\n");
                                  break;
                        case 31..45:
                    TP()->restore_spell_points(-(TO()->query_sp()/2));
write("The Psi-Lord drains your mental energy!\n");
TLR( ENV(), "The Psi-Lord drains "+TPN+"'s mental energy!\n");
                                  break;
			}
	return:: hit_player(dam);
	}
