inherit "obj/weapon";
reset(arg) {
	::reset(arg);
	if (!arg) {
		set_name("claws");
		set_alias("jackal claws");
		set_class(17);
		set_short("Jackal claws");
		set_long("The claws of a jackal.\n");
		set_value(700);
		set_weight(2);
	}
}
