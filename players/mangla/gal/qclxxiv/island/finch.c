#include "/players/qclxxiv/island/bird.h"
object loot1;
shyness() { return 4; }
reset(arg) {
	::reset(arg);
	if (arg) return;
	 load_chat(12,({
		"tweet tweet.\n",
		"tweeet.\n",
		"tweet.\n",
	  }));
	 load_a_chat(11,({
        "Finch tweets angrily.\n",
        "Finch tweets angrily.\n",
	  }));
	set_name("finch");
	set_alias("finch");
	set_level(3);
   	set_wc(6);
	set_ac(1);
   	set_hp(90);
	set_sp(10);
	set_al(3);
	set_whimpy(50);
	set_race("bird");
   	set_short("A finch");
   	set_long("A finch. A small bird with some red and yellow in its feathering.\n");
	set_size(1);
}

second_life() {
/*
	if (!loot1) {
		say(
"As you see the gall animal die, you wonder how much things would fit in\n"
+"this giant one's gall bladder. It would be fit for a bag you imagine.\n");
		PLACE_IN_THIS(loot1,HOME+"leaf2/ganimalbag");
	}
*/
	return 0;
}

can_climb() { return 1; }
run_method() { return "fly"; }
