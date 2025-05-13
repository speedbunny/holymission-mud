inherit "obj/weapon";
reset(arg) {
	::reset(arg);
	if (!arg) {
		set_name("scissors");
		set_alias("tail");
		set_class(7);
		set_short("The scissors of an earwig");
		set_long("The scissors of an earwig, actually being the tail.\n");
		set_value(60);
		set_weight(0);
	}
}
