inherit "room/room";
#include "/players/trout/defs.h"

reset(tick){
	::reset(tick);
	if(tick) return;
switch(RAN(100)){
	case 0..25: MO(CO(MM+"/guard1"), TO());
		    break;
	case 26..99: break;
		}
	}

