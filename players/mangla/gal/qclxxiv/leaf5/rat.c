#include "/players/qclxxiv/mymonster.h"
reset(arg) {
	::reset(arg);
	if (arg) return;
	load_chat(5,({
        "Rat potters about.\n",
        "Peeep.\n",
        "Peep.\n",
	  }));
	 load_a_chat(10,({
        "PEEEP.\n",
        "PEEP.\n",
		"Rat shows its teeth.\n",
	  }));
	set_name("rat");
	set_alias("rat");
	set_race("skum");
	set_level(5);
   	set_wc(7);
	set_ac(1);
   	set_hp(132);
	set_sp(50);
	set_al(-4);
   	set_aggressive(0);
	set_whimpy(20);
   	set_short("A rat");
   	set_long("A rat, its little red eyes staring at you.\n");
	set_size(3);
}

