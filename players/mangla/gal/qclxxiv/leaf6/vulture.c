#include "/players/qclxxiv/mymonster.h"
object claws;
reset(arg) {
	::reset(arg);
	if (arg) return;
	load_chat(10,({ "The vulture looks at you with its beady eyes.\n", 
						"The vulture screeches ghastly.\n", }));
	load_a_chat(10,({ "The vulture tries to pick out your eye.\n", 
						"The vulture scratches you with its claws.\n", }));
	set_name("vulture");
	set_race("skum");
	set_level(14);
   	set_wc(12);
	set_ac(4);
   	set_hp(550);
	set_sp(140);
	set_al(-6);
   	set_aggressive(0);
   	set_short("A vulture");
   	set_long("A hungry vulture, waiting for somebody to die.\n");
	set_size(3);
	PLACE_IN_THIS(claws,HOME+"leaf6/vultclaws");
	init_command("wield claws");
}

