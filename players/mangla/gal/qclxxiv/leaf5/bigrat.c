#include "/players/qclxxiv/mymonster.h"
reset(arg) {
	::reset(arg);
	if (arg) return;
	load_chat(5,({
        "Big rat potters about.\n",
        "Peeeep.\n",
        "Peeep.\n",
	  }));
	 load_a_chat(10,({
        "PEEEEP.\n",
        "PEEEP.\n",
		"Big rat shows its teeth.\n",
	  }));
	set_name("big rat");
	set_alias("rat");
	set_race("skum");
	set_level(10);
   	set_wc(10);
	set_ac(3);
   	set_hp(322);
	set_sp(70);
	set_al(-8);
   	set_aggressive(0);
	set_whimpy(10);
   	set_short("A big rat");
   	set_long("A big rat, its little red eyes staring at you.\n");
	set_size(3);
}

