inherit "room/room";
#include "/players/trout/defs.h"

reset(tick){
	::reset(tick);
	if(tick) return;
switch(RAN(100)){
	case 0..35: MO(CO(MM+"/peasant"), TO());
		    break;
	default: break;
		}
	}

init(){
	::init();
	if(present("tag1", this_player())){
		MO(CO(MM+"/calvary"), TO());
		write("The calvary from Honno Ji follow you, refusing "+
		"to let a thief go unpunished!\n");
		return 1;
		}
	return ;
	}

