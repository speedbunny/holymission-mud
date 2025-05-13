	inherit "obj/armour";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_id("golden crown");
	set_alias("crown");
	set_weight(2);
	set_ac(2);
	set_type("helmet");
	set_size(3);
	set_short("a golden crown");
	set_long("Beautiful golden crown of king Vladimir.\n");

	set_value(5000);
}
