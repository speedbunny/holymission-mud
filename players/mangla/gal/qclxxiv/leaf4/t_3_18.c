#include "/players/qclxxiv/leaf4/tideroom.h"
reset(arg) { 
	::reset();
	if (arg) return;
	long_desc = " \n";
	set_loc_and_exits( 3, 18 ); /* set col and row and make 8 exits */
	dest_dir[0] = LEAF4+"beach";
}
