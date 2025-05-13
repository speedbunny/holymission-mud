	inherit "obj/armour";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("helmet");
	set_alias("shield");
	set_short("A helmet of hogan");
	set_long("This helmet is from famous Hogan's collection of armours.\n");
	set_type("helmet");
	set_size(0);
	set_ac(1);
	set_weight(2);
	set_value(300);
}
