/* q06 */
#include "/players/qclxxiv/leaf5/qroom.h"
nr() { return 6; }
mymonster() { return "waterghost"; }
condition(tp) { return (set_light(0)>=3); }

NO_EXIT( 
"Inside a small room",
"Inside a small room. A plaque is fitted against the eastern wall.\n",
0 )
