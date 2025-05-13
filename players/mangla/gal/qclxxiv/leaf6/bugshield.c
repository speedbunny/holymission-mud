inherit "obj/armour";

reset(arg) {
	::reset(arg);
	if (!arg) {
		set_name("shield");
		set_ac(1);
		set_type("shield");
		set_size(3);
		set_short("A sow-bug shield");
		set_long("The shield of a dirty sow-bug.\n");
		set_value(50);
		set_weight(1);
	}
}
