#include "/players/qclxxiv/island/ianimal.h"
object loot1;
reset(arg) {
	::reset(arg);
	if (arg) return;
	set_name("animal");
	set_alias("animal");
	set_level(7);
   	set_wc(8);
	set_ac(4);
   	set_hp(199);
	set_sp(70);
	set_al(3);
   	set_short("An animal");
   	set_long("An animal, of unknown type.\n");
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


