#include "/players/qclxxiv/mymonster.h"
object claws;
reset(arg) {
	::reset(arg);
	if (arg) return;
	load_chat(10,({ "The hyena howls expectantly.\n", 
						"The hyena slavers as he looks at you.\n", }));
	load_a_chat(10,({ "The hyena tries to bite you in the leg.\n", 
				"The hyena howls in anger and fear at the same time.\n", }));
	set_name("hyena");
	set_race("skum");
	set_level(18);
   	set_wc(14);
	set_ac(6);
   	set_hp(834);
	set_sp(100);
	set_al(-8);
   	set_aggressive(0);
   	set_short("A hyena");
   	set_long(
"A howling hyena slavers as he looks at you. Probably there's larger\n"
+"predators around. The skum howls expectantly.\n");
	set_size(4);
	set_whimpy();
	PLACE_IN_THIS(claws,HOME+"leaf6/hyenaclaws");
/*	init_command("wield claws"); */
}

