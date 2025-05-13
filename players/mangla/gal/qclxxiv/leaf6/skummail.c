inherit "obj/armour";

reset(arg) {
	::reset(arg);
	if (!arg) {
		set_name("mail");
		set_alias("skum mail");
		set_ac(3);
/*		set_type("mail"); */
		set_short("A skum mail");
		set_long(
"A skum mail. A good piece of armour against all skum and other monsters.\n");
		set_value(500);
		set_weight(3);
	}
}
