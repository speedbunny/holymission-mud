#include "/players/qclxxiv/mymonster.h"
object shield;
reset(arg) {
	::reset(arg);
	if (arg) return;
	load_chat(10,({ "bzzzzz\n", "bzzzzzzt\n", }));
	load_a_chat(10,({ "BZZZZZZZZ\n", "BZZZZZTT\n", }));
	set_name("louse");
	set_race("skum");
	set_level(2);
   	set_wc(6);
	set_ac(0);
   	set_hp(70);
	set_sp(20);
	set_al(-1);
   	set_aggressive(0);
   	set_short("A louse");
   	set_long("An irritating little louse.\n");
	set_size(1);
	set_whimpy();
	PLACE_IN_THIS(shield,HOME+"leaf6/liceshield");
	init_command("wear shield");
}

