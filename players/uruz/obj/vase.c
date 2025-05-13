inherit "obj/thing";
#include "/players/trout/defs.h"
	
reset(tick){
	::reset(tick);
	if(tick) return;
	set_name("vase");
	set_can_get(1);
	set_weight(2);
	switch(RAN(3)){
		case 0: set_long("This vase pays homage to Tokugawa's "+
			"ally, Toyotomi Hideyoshi. \n");
			set_value(500);
			break;
		case 1: set_long("This vase is a tribute to one of the "+
			"greatest foes Tokugawa ever challenged, Khan! \n");
			set_value(600);
			break;
		case 2: set_long("This vase is is painted expertly, in a "+
			"stunning design! \n");
			set_value(800);
			break;
			}
		}
