inherit "obj/food";

reset(arg) {
	if(arg) return;
	set_name("roastfish");
	set_alias("fish");
	set_short("Spicy roastfish");
	set_long("Spicy and ital roastfish, with a crispy skin.\n");
	set_value(10);
	set_weight(1);
	set_eater_mess(
			"Mjumm very edible indeed these roastfishes, spicy and thing.\n");
	set_strength(15);
}
