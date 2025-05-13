#include "/players/qclxxiv/island/ianimal.h"
shyness() { return 4; }
object loot1;
reset(arg) {
	::reset(arg);
	if (arg) return;
	set_name("ermine");
	set_alias("ermine");
	set_level(8);
   	set_wc(10);
	set_ac(10);
   	set_hp(300);
	set_sp(40);
	set_al(-5);
   	set_short("An ermine");
   	set_long("An ermine, its fur still white, except for its black tail.\n");
	set_size(3);
}

second_life() {
	PLACE_IN_THIS(loot1,"obj/armour");
	loot1->set_type("cloak");
	loot1->set_name("fur");
	loot1->set_short("An ermine fur");
	loot1->set_long("An ermine fur, white and soft.\n");
	loot1->set_ac(1);
	loot1->set_value(200);
	loot1->set_weight(1);
	return 0;
}

run_OK(room) {
	if (room->query_forest_dune_dell()) return 1;
	return 0;
}
can_climb() { return 1; }
predator() { return 1; }
