/* q03 */
#include "/players/qclxxiv/leaf5/qroom.h"
nr() { return 3; }
mymonster() { return "minotaur"; }
condition(tp) { return (tp->query_sp()<=10); }

NO_EXIT( /* REGION+"h03", "north", */
"Inside a small room",
"Inside a small room. A plaque is fitted against the southern wall.\n",
0 )
