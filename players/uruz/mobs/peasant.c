inherit "obj/monster";
#include "/players/trout/defs.h"

reset(arg) {
	::reset(arg);
	if(arg) return;
	set_name("peasant");
	set_level(5);
	set_al( RAN(200) - 100 );
	set_hp(70);
	set_race("human");
	set_short("Peasant");
	set_long("A simple peasant worker of Mikawa. He is dressed in plain "+
	"clothing, and wears a large sun hat. He looks very tired. \n");
	set_ac(1);
	set_gender(1);
        switch(random(4)){
		case 0: MO( CO(WW+"/fang"), TO() );
			IC("powerup");
			break;
		case 1: MO( CO(WW+"/kama"), TO() );
			
			IC("powerup");
			break;
		case 2: MO( CO(WW+"/tui-fa"), TO() );
		
			IC("powerup");
			break;
		case 3: MO( CO(WW+"/bo"), TO() );
			IC("powerup");
		default: break;
			}
	}
