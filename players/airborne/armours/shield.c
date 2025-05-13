inherit "/obj/armour";

reset(arg) {
	::reset(arg);
	if(arg) return 1;
	set_type("shield");
	set_size(0);
	set_value(100);
	set_name("large shield");
	set_alias("shield");
	set_ac(2);
	set_weight(2);
	set_short("A large shield");
	set_long("This is a very large shield with the crest of Kane the Troll on it.\n");
	return 1;
}
