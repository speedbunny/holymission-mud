	inherit "obj/armour";

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_name("pearl necklace");
	set_alias("necklace");
	set_short("A pearl necklace");
	set_long("This necklace is masterpiece of your hands. Pearls beam against sun\n"
	+ "diferent colors. When you dont know that it is forgery of famous Hogan\n"
	+ "necklace, you think that is it original.\n");
	set_value(999);
	set_weight(1);
	set_ac(1);
	set_type("amulet");
}
	init() {
	::init();
	add_action("daj","give");
}
	daj(str) {
	if(str=="necklace to nixie"&&present("nixie",environment(this_player()))) {
	return 1;
}}

