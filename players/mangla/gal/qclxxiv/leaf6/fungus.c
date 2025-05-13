inherit "obj/food";

reset(arg) {
	if(arg) return;
	set_name("fungus");
	set_short("A fungus");
	set_long("A slimy primitive mushroom.\n");
	set_value(10);
	set_weight(2);
	set_eater_mess( "This is hardly what one would call an edible mushroom.\n"
					+"But it's your stomach, so do as you please.\n" );
	set_strength(10);
}
