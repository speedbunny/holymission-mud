inherit "players/trout/mobs/guard_help";
#include "/players/akira/defs.h"

reset(arg){
	::reset(arg);
	if(arg) return;
         set_name("Evil Lord Houron");
	 set_alias("lord");
	 set_alt_name("houron");
	set_long("An evil Houron Lord bemt on killing all!\n");
	set_level(20);
        set_number_of_arms(4); /*I wanted the extra attacks*/
	set_gender(1);
        GP(10000);
        set_wc(15);
        set_ac(20);
	}
hit_player(dam){
	switch(RAN(100)){
			case 0..20:
				  TP()->HIT(50);
write("Houron hits you with a powerful claw strike!\n");
TLR( ENV(), "Houron hits "+TPN+" with a claw strike.\n");
				  break;
			default: break;
                       case 21..30:
                                  TP()->add_poison(40);
write("Houron picks you up and sinks his teeth into you!\n");
TLP( ENV(), "Houron picks up "+TPN+" and bites them.\n");
                                  break;
                        case 31..45:
                    TP()->restore_spell_points(-(TP()->query_sp()/2));
write("Houron grabs you and draws the energy from your body!\n");
TLP( ENV(), "Houron picks up "+TPN+" they don't look so good!\n");
                                  break;
			}
	return:: hit_player(dam);
	}
