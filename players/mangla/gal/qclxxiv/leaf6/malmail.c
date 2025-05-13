inherit "obj/armour";

reset(arg) {
	::reset(arg);
	if (!arg) {
		set_name("mail");
		set_alias("malthezer mail");
		set_ac(4);
/*		set_type("mail"); */
		set_short("A Malthezer mail");
		set_long(
"A Malthezer mail. Very powerful armour of a fine design.\n");
		set_value(700);
		set_weight(2);
	}
}
