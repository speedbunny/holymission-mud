inherit "obj/armour";

reset(arg) {
	::reset(arg);
	if (!arg) {
		set_name("gloves");
		set_ac(1);
		set_type("glove");
		set_size(0);
		set_short("Gloves of light");
		set_long("Gloves of light, keep lighting you everywhere.\n");
		set_value(250);
		set_weight(1);
		set_arm_light(1);
	}
}

query_monk_wear() { return 1; }
