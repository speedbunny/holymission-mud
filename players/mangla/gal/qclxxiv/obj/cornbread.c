inherit "obj/food";

reset(arg) {
	if(arg) return;
	set_name("cornbread");
	set_alias("bread");
	set_short("An Ital cornbread");
	set_long("An Ital cornbread made of the best ital corn.\n");
	set_value(100);
	set_weight(1);
	set_eater_mess(
			"You carefully chew the very nutricious cornbread, aahhhh.\n");
	set_strength(25);
}
