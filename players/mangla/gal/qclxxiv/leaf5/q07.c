/* q07 */
#include "/players/qclxxiv/leaf5/qroom.h"
nr() { return 7; }
mymonster() { return "carnivore"; }
condition(tp) { 
	object obj;		
	int i;
	obj = all_inventory(tp);
	return (present("herbalsoul174",tp)); 
}


NO_EXIT( /* REGION+"h07", "west", */
"Inside a small room",
"Inside a small room. A plaque is fitted against the eastern wall.\n",
0 )
