inherit "obj/weapon";
reset(arg) {
	::reset(arg);
	if (!arg) {
		set_name("teeth");
		set_alias("flea's teeth");
		set_class(5);
		set_short("Flea's teeth");
		set_long("The teeth of a blood-sucking flea.\n");
		set_value(40);
		set_weight(0);
	}
}
