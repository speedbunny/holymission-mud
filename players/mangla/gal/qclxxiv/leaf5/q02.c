/* q02 */
#include "/players/qclxxiv/leaf5/qroom.h"
nr() { return 2; }
mymonster() { return "lion"; }
condition(tp) { return (!(tp->query_money())); }

NO_EXIT( /* REGION+"h02", "north", */
"Inside a small room",
"Inside a small room. A plaque is fitted against the southern wall.\n",
0 )
