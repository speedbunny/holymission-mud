#include "/players/qclxxiv/mymonster.h"
object teeth;
reset(arg) {
	::reset(arg);
	if (arg) return;
	load_chat(10,({ "A flea is looking for some blood\n", 
					"A flea jumps around\n", }));
	load_a_chat(10,({ "You hear the flea's teeth clicking\n", 
						"The flea tries to bite you\n", }));
	set_name("flea");
	set_race("skum");
	set_level(4);
   	set_wc(7);
	set_ac(1);
   	set_hp(107);
	set_sp(40);
   	set_spell_mess1("The flea bites and sucks the blood of its opponent.");
   	set_spell_mess2("The flea bites you and sucks your blood.");
	set_chance(20);
	set_spell_dam(4);
	set_al(-2);
   	set_aggressive(0);
   	set_short("A flea");
   	set_long("A blood-sucking flea.\n");
	set_size(1);
	set_whimpy();
	PLACE_IN_THIS(teeth,HOME+"leaf6/fleateeth");
	init_command("wield teeth");
}

