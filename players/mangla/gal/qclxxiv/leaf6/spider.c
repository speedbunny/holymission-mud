#include "/players/qclxxiv/mymonster.h"
reset(arg) {
	::reset(arg);
	if (arg) return;
	set_name("spider");
	set_race("spider");
	set_level(7);
   	set_wc(9);
	set_ac(3);
   	set_hp(197);
	set_sp(30);
	set_al(3);
   	set_aggressive(0);
   	set_short("A spider");
   	set_long("An big spider, looking for harmful insects to eat.\n");
	set_size(3);
	set_whimpy();
}

