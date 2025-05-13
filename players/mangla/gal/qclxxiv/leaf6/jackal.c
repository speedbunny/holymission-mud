#include "/players/qclxxiv/mymonster.h"
object claws;
reset(arg) {
	::reset(arg);
	if (arg) return;
	load_chat(10,({ "The jackal grimaces and laughs a disgusting laugh.\n", 
			"The jackal starts walking around you.\n", }));
	load_a_chat(10,({ "The jackal tries to scratch you with his claws.\n", 
				"The jackal tries to get behind you.\n", }));
	set_name("jackal");
	set_race("skum");
	set_level(18);
   	set_wc(14);
	set_ac(6);
   	set_hp(834);
	set_sp(100);
	set_al(-8);
   	set_aggressive(0);
   	set_short("A jackal");
   	set_long(
"A grimacing jackal eyes you wearily. It seems to be laughing. It's a very\n"
+"ugly laugh though making you shiver with disgust.\n");
	set_size(4);
	set_whimpy();
	PLACE_IN_THIS(claws,HOME+"leaf6/jackalclaws");
	/* init_command("wield claws"); */
}

