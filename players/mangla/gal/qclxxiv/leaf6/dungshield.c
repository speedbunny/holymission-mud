inherit "obj/armour";

reset(arg) {
	::reset(arg);
	if (!arg) {
		set_name("shield");
		set_ac(1);
		set_type("shield");
		set_size(2);
		set_short("A dung-beetle shield");
		set_long("The shield of a stinking dung-beetle.\n");
		set_value(30);
		set_weight(0);
	}
}
