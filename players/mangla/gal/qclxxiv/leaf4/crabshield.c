inherit "obj/armour";

reset(arg) {
	::reset(arg);
	if (!arg) {
		set_name("shield");
		set_ac(1);
		set_type("shield");
		set_short("A giant crab shield");
		set_long("The tough shield of a giant Wadden crab.\n");
		set_value(100);
		set_weight(1);
	}
}
