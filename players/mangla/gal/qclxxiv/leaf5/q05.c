/* q05 */
#include "/players/qclxxiv/leaf5/qroom.h"
nr() { return 5; }
mymonster() { return "fireghost"; }
condition(tp) { return (set_light(0)<=1); }

NO_EXIT( /* REGION+"h05", "north", */
"Inside a small room",
"Inside a small room. A plaque is fitted against the southern wall.\n",
1 )
