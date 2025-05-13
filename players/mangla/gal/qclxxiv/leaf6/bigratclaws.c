inherit "obj/weapon";
reset(arg) {
	::reset(arg);
	if (!arg) {
		set_name("claws");
		set_alias("rat claws");
		set_class(10);
		set_short("Rat claws");
		set_long("The claws of a big rat.\n");
		set_value(100);
		set_weight(1);
	}
}
