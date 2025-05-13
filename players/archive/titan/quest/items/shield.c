	inherit "obj/armour";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("shield");
	set_alias("shield");
	set_short("A shield of hogan");
	set_long("This shield is from famous Hogan's collection of armours.\n");
	set_type("shield");
	set_size(0);
	set_ac(2);
	set_weight(3);
	set_value(1000);
}
