#include "/players/qclxxiv/mymonster.h"
object tail;
reset(arg) {
	::reset(arg);
	if (arg) return;
	load_a_chat(10,({ "The skunk lifts its tail.\n", 
						"You smell a sickening stench.\n", }));
	set_name("skunk");
	set_race("skum");
	set_level(13);
   	set_wc(11);
	set_ac(5);
   	set_hp(485);
	set_sp(140);
	set_al(5);
   	set_aggressive(0);
   	set_short("A skunk");
   	set_long("An innocent looking skunk.\n");
	set_size(3);
	PLACE_IN_THIS(tail,HOME+"leaf6/skunktail");
	init_command("wield tail");
}

