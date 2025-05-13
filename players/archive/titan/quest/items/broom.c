	inherit "obj/weapon";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("broom");
	set_type(2);
	set_value(30);
	set_class(5);
	set_weight(1);
	set_short("a broom");
	set_long("Broom with wooden bromholder");
}
