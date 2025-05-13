inherit "/obj/thing";
#include "/players/trout/defs.h"
	
reset(tick){
	::reset(tick);
	if(tick) return;
	set_name("statue");
	set_can_get(1);
	set_weight(2);
	switch(RAN(3)){
		case 0: set_long("This is a small statue of the legendary "+
			"bard, Exos! \n");
			set_value(200);
			break;
		case 1: set_long("This is a small statue of the Japanese "+
			"god of luck, Daikoku. He appears as a middle-aged "+
			"balding man with a large belly. \n");
			set_value(20);
			break;
		case 2: set_long("This is a small statue of a samurai warrior"+
			". He is in an action pose! \n");
			set_value(400);
			break;
		}
	}
