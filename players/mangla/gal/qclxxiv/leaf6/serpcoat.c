inherit "obj/armour";

reset(arg) {
	::reset(arg);
	if (!arg) {
		set_name("coat");
		set_ac(1);
		set_type("cloak");
		set_size(0);
		set_short("Coat of light");
		set_long("Coat of light, keeps lighting you everywhere.\n");
		set_value(450);
		set_weight(1);
		set_arm_light(1);
	}
}

query_monk_wear() { return 1; }
