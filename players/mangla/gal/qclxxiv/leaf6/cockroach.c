#include "/players/qclxxiv/mymonster.h"
object shield;
query_plural() { return "cockroaches"; }
reset(arg) {
	::reset(arg);
	if (arg) return;
	set_name("cockroach");
	set_race("skum");
	set_level(8);
   	set_wc(9);
	set_ac(2);
   	set_hp(234);
	set_sp(70);
	set_al(-4);
   	set_aggressive(0);
   	set_short("A cockroach");
   	set_long("A tough dark brown cockroach potters about.\n");
	set_size(4);
	PLACE_IN_THIS(shield,HOME+"leaf6/crshield");
	init_command("wear shield");
}

