inherit "/obj/armour";

reset(arg) {
	::reset(arg);
	if(arg) return 1;
	set_type("robe/amulet");
	set_short("Mystic Robe of the Old Ones.");
	set_long("This is the mystic robe of the Old Ones that Jafros wears.\n" + "The darkness from the robe envelopes the area.\n");
	set_name("mystic robe");
	set_ac(2);
	set_weight(2);
	set_alias("robe");
	set_value(1000);
	set_arm_light(-1);
    return 1;
}
