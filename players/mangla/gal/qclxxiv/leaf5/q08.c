/* q08 */
#include "/players/qclxxiv/leaf5/qroom.h"
nr() { return 8; }
mymonster() { return "whirlwind"; }
condition(tp) { 
	return ( (tp->query_weight()<3 && !(tp->query_intoxination()))
			|| tp->query_alignment_title()=="saintly" );
}

NO_EXIT( /* REGION+"h08", "west", */
"Inside a small room",
"Inside a small room. A plaque is fitted against the eastern wall.\n",
0 )
