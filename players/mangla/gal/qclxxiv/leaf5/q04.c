/* q04 */
#include "/players/qclxxiv/leaf5/qroom.h"
nr() { return 4; }
mymonster() { return "hailcloud"; }
condition(tp) { 
	object obj;		
	int i;
	string m, s;
	obj = all_inventory(tp);
	for (i=0; i<sizeof(obj); i++) 
		if (obj[i]->id("note174")) {
			m = obj[i]->query_text();
			if (m) {
				m = lower_case(m);
				if (sscanf(m,"%snjoq makl njaq", s)) 
					return 1;
			}
		}
	return 0;
}

NO_EXIT( /* REGION+"h04", "north", */
"Inside a small room",
"Inside a small room. A plaque is fitted against the southern wall.\n",
0 )
