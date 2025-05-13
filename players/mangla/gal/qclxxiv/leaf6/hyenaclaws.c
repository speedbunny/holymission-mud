inherit "obj/weapon";
reset(arg) {
	::reset(arg);
	if (!arg) {
		set_name("claws");
		set_alias("hyena claws");
		set_class(16);
		set_short("Hyena claws");
		set_long("The claws of a hyena.\n");
		set_value(600);
		set_weight(2);
	}
}
