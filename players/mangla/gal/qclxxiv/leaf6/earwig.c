#include "/players/qclxxiv/mymonster.h"
object scissors;
reset(arg) {
	::reset(arg);
	if (arg) return;
	set_name("earwig");
	set_race("skum");
	set_level(6);
   	set_wc(8);
	set_ac(2);
   	set_hp(162);
	set_sp(60);
	set_al(-3);
   	set_aggressive(0);
   	set_short("An earwig");
   	set_long("An ugly earwig, pointing its scissors-like tail at you.\n");
	set_size(1);
	PLACE_IN_THIS(scissors,HOME+"leaf6/ewscissors");
	init_command("wield scissors");
}

