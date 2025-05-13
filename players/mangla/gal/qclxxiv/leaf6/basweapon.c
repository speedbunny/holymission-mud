inherit "obj/weapon";
reset(arg) {
	::reset(arg);
	if (!arg) {
		set_name("banger");
		set_alias("basilisk banger");
		set_class(20);
		set_short("Basilisk banger");
		set_long(
"A basilisk banger. The mighty weapon of a baneful basilisk.\n" );
		set_value(1000);
		set_weight(3);
	}
}
