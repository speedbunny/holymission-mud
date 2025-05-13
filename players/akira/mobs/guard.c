inherit "players/trout/mobs/guard_help";
#include "/players/trout/defs.h"

reset(arg){
	::reset(arg);
	if(arg) return;
        set_name("Tower Guard");
        set_long("This is a tower guard. He looks to have no weapon, and as\n"+
                 "far as guards go he looks like a wimp. His arms are small\n"+
                 "and he doesn't look like he could take much of a hit. On\n"+
                 "his chest is the crest of the Psionicist Guild.\n");
	set_alias("guard");
	set_al(350);
	set_level(20);
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
                                  TP()->HIT(25);
write("The guard hits you with a powerful Mind Bolt!\n");
TLR( ENV(), "A guard looks "+TPN+" in the eyes!\n");
				  break;
			default: break;
			}
	return:: hit_player(dam);
	}
