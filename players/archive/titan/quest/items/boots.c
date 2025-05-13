	inherit "obj/armour";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("boots");
	set_alias("boots of Hogan");
	set_short("Boots of hogan");
	set_long("This boots is from famous Hogan's collection of armours.\n");
	set_type("boots");
	set_size(0);
	set_ac(1);
	set_weight(2);
	set_value(300);
}
