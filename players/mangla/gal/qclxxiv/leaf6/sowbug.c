#include "/players/qclxxiv/mymonster.h"
object shield;
reset(arg) {
	::reset(arg);
	if (arg) return;
	set_name("sow-bug");
	set_alias("bug");
	set_race("skum");
	set_level(5);
   	set_wc(7);
	set_ac(1);
   	set_hp(150);
	set_sp(50);
	set_al(2);
   	set_aggressive(0);
   	set_short("A sow-bug");
   	set_long("A dirty sow-bug. It doesn't do any harm though.\n");
    set_whimpy();
	set_size(3);
	PLACE_IN_THIS(shield,HOME+"leaf6/bugshield");
	init_command("wear shield");
}

