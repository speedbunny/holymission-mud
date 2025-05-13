#include "/players/qclxxiv/island/ianimal.h"
shyness() { return 4; }
reset(arg) {
	::reset(arg);
	if (arg) return;
	 load_chat(7,({
		"peep peeep.\n",
		"peeep.\n",
		"peep.\n",
	  }));
	 load_a_chat(11,({
        "Meadow mouse squeaks angrily.\n",
        "Meadow mouse squeaks angrily.\n",
	  }));
	set_name("mouse");
	set_alias("meadow mouse");
	set_level(3);
   	set_wc(6);
	set_ac(1);
   	set_hp(90);
	set_sp(10);
	set_al(4);
	set_whimpy(50);
   	set_short("A meadow mouse");
   	set_long("A meadow mouse. A little innocent gray rodent.\n");
	set_size(1);
}
run_OK(room) {
	if (room->forest_dune_dell()) return 1;
	return 0;
}

prey() { return 1; }
