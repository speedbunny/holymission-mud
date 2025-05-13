inherit "obj/food";

reset(arg) {
	if(arg) return;
	set_name("mould");
	set_short("Mould");
	set_long(
		"This must have been a piece of wood, but now it's mostly mould.\n");
	set_value(10);
	set_weight(2);
	set_eater_mess( "You have to vomit, but can keep part of it inside.\n");
	set_strength(8);
}
