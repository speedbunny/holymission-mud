#include "/players/qclxxiv/island/ianimal.h"
predator() { return 1; }
shyness() { return 1; }
object loot1;
reset(arg) {
	::reset(arg);
	if (arg) return;
	 load_chat(10,({
		"Crab opens and closes its scissors.\n",
		"Crab walks a bit to the left.\n",
		"Crab walks a bit to the right.\n",
	  }));
	 load_a_chat(15,({
        "Crab reaches toward its opponent with its mean-looking scissors.\n",
		"Crab opens and closes its scissors with clacking noises.\n",
	  }));
	set_name("crab");
	set_alias("crab");
	set_level(10);
   	set_wc(12);
	set_ac(10);
   	set_hp(330);
	set_sp(30);
	set_al(5);
   	set_short("A crab");
   	set_long("A blue crab, of respectable size.\n");
	set_size(3);
}

second_life() {
	PLACE_IN_THIS(loot1,"obj/armour");
	loot1->set_type("shield");
	loot1->set_name("shield");
	loot1->set_short("A crab shield");
	loot1->set_long("A crab shield, apparently from a big blue crab.\n");
	loot1->set_ac(1);
	loot1->set_value(100);
	loot1->set_weight(1);
	return 0;
}

run_OK(room) {
	if (room->query_beach()) return 1;
	return 0;
}
