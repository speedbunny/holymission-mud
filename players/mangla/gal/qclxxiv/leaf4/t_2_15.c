#include "/players/qclxxiv/leaf4/tideroom.h"
reset(arg) { 
	::reset();
	if (arg) return;
	long_desc = " \n";
	set_loc_and_exits( 2, 15 ); /* set col and row and make 8 exits */
}
