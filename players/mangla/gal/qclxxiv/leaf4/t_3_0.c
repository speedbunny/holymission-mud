#include "/players/qclxxiv/leaf4/tideroom.h"
object sign;
reset(arg) { 
	::reset();
	if (!sign) {
		sign = clone_object(LEAF4+"addsign");
		move_object(sign, this_object() );
	}
	if (arg) return;
	long_desc = " \n";
	set_loc_and_exits( 3, 0 ); /* set col and row and make 8 exits */
	dest_dir[8] = LEAF4+"grifroom";
}
