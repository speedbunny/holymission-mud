/* q01 */
#include "/players/qclxxiv/leaf5/qroom.h"
nr() { return 1; }
mymonster() { return "inkblob"; }
condition(tp) { 
	object obj;		
	int i;
	obj = all_inventory(tp);
	for (i=0; i<sizeof(obj); i++) 
		if (obj[i]->query_weapon() && obj[i]->weapon_class()>0) return 0;
	return (present("book",tp)||present("notebook",tp)); 
}

NO_EXIT( /* REGION+"h01", "north", */
"Inside a small room",
"Inside a small room. A plaque is fitted against the southern wall.\n",
0 )

