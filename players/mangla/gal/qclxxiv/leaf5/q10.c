/* q10 */
#include "/players/qclxxiv/leaf5/qroom.h"
nr() { return 10; }
mymonster() { return "snake"; }
condition(tp) { 
	object obj;		
	int i;
	obj = all_inventory(tp);
	for (i=0; i<sizeof(obj); i++) 
		if (obj[i]->id("tam174") && obj[i]->query_armour()
				&& obj[i]->query_worn()) return 1;
	return 0;
}

NO_EXIT( /* REGION+"h10", "west", */
"Inside a small room",
"Inside a small room. A plaque is fitted against the eastern wall.\n",
0 )
