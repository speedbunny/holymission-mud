#include "/players/qclxxiv/island/bird.h"
shyness() { return 2; }
object loot1;
reset(arg) {
	::reset(arg);
	if (arg) return;
	 load_chat(7,({
		"Hawk turns its head to the left.\n",
		"Hawk turns its head to the right.\n",
		"Shreeek.\n",
	  }));
	 load_a_chat(11,({
        "Hawk shreeks angrily.\n",
        "Hawk shreeks angrily.\n",
	  }));
	set_name("hawk");
	set_alias("hawk");
	set_level(12);
   	set_wc(12);
	set_ac(5);
   	set_hp(430);
	set_sp(30);
	set_al(-5);
   	set_short("A hawk");
   	set_long("A hawk. Its dark brown feathering stippled with lighter brown.\n");
	set_size(2);
}

second_life() {
	PLACE_IN_THIS(loot1,"obj/weapon");
	loot1->set_name("claw");
	loot1->set_short("A hawks claw");
	loot1->set_long("A hawks claw, small, but having sharp nails.\n");
	loot1->set_class(12);
	loot1->set_value(300);
	loot1->set_weight(1);
	return 0;
}

run_OK(room) {
	if (room->query_beach() || room->query_whirl()) return 0;
	return 1;
}
can_climb() { return 1; }
run_method() { return "fly"; }
predator() { return 1; }
