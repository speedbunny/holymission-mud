/* q09 */
#include "/players/qclxxiv/leaf5/qroom.h"
nr() { return 9; }
mymonster() { return "cyclops"; }
condition(tp) { return (tp->query_hp()<=30); }

NO_EXIT( /* REGION+"h09", "west", */
"Inside a small room",
"Inside a small room. A plaque is fitted against the eastern wall.\n",
0 )
