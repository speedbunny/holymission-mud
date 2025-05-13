inherit "obj/armour";

reset(arg) {
	::reset(arg);
	if (!arg) {
		set_name("boots");
		set_ac(1);
		set_type("boots");
		set_size(0);
		set_short("Boots of light");
		set_long("Boots of light, keep lighting you everywhere.\n");
		set_value(350);
		set_weight(1);
		set_arm_light(1);
	}
}

query_monk_wear() { return 1; }
