inherit "/obj/monster";

reset(arg) {
	::reset(arg);
	if (arg) return;
	set_name("test");
	set_alias("test");
	set_level(1);
	set_short("test");
	set_long("A test monster.\n");
}
