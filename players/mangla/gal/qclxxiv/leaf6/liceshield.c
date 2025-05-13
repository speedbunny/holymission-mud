inherit "obj/armour";

reset(arg) {
	::reset(arg);
	if (!arg) {
		set_name("shield");
		set_ac(1);
		set_type("shield");
		set_size(1);
		set_short("The shield of a louse");
		set_value(20);
		set_weight(0);
	}
}
