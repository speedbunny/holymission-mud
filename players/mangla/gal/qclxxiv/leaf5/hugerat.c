#include "/players/qclxxiv/mymonster.h"
reset(arg) {
	::reset(arg);
	if (arg) return;
	load_chat(5,({
        "Huge rat potters about.\n",
        "Peeeep.\n",
        "Peeep.\n",
	  }));
	 load_a_chat(10,({
        "PEEEEP.\n",
        "PEEEP.\n",
		"Huge rat shows its teeth.\n",
	  }));
	set_name("huge rat");
	set_alias("rat");
	set_race("skum");
	set_level(15);
   	set_wc(15);
	set_ac(5);
   	set_hp(620);
	set_sp(100);
	set_al(-12);
   	set_aggressive(0);
   	set_short("A huge rat");
   	set_long("A huge rat, its little red eyes staring at you.\n");
	set_size(4);
}

