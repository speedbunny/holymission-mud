inherit "obj/weapon";
reset(arg) {
	::reset(arg);
	if (!arg) {
		set_name("claws");
		set_alias("vulture claws");
		set_class(14);
		set_short("Vulture claws");
		set_long("The claws of a vulture.\n");
		set_value(400);
		set_weight(2);
	}
}
