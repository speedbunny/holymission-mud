inherit "obj/armour";

reset(arg) {
	::reset(arg);
	if (!arg) {
		set_name("shield");
		set_alias("cockroach shield");
		set_ac(1);
		set_type("shield");
		set_size(0);
		set_short("A cockroach shield");
		set_long("The tough shield of a cockroach.\n");
		set_value(60);
		set_weight(1);
	}
}
