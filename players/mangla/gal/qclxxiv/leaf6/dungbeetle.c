#include "/players/qclxxiv/mymonster.h"
object shield;
reset(arg) {
	::reset(arg);
	if (arg) return;
	set_name("dung-beetle");
	set_alias("beetle");
	set_race("skum");
	set_level(3);
   	set_wc(6);
	set_ac(1);
   	set_hp(84);
	set_sp(30);
	set_al(1);
   	set_aggressive(0);
   	set_short("A dung-beetle");
   	set_long("A stinking dung-beetle. It's ugly but harmless.\n");
	set_size(2);
	PLACE_IN_THIS(shield,HOME+"leaf6/dungshield");
	init_command("wear shield");
}

