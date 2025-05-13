inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    if(!arg){
	set_name("horn");
	set_class(7);
	set_weight(3);
	set_value(60);
	set_alt_name("goat horn");
	set_alias("horns");
	set_short("Goat horns");
	set_long("A pair of goat horns.\n");
    }
}
