inherit "obj/thing";

reset(arg) {
    ::reset(arg);
    if(!arg){
	set_name("scroll");
	set_weight(1);
	set_value(100);
	set_alt_name("ancient scroll");
	set_alias("scroll");
	set_short("Scroll");
	set_long("An ancient scroll.\n"+
	  "The letters are drawn on it in an old way.\n"+
	  "You can't read them yet.\n");
	set_can_get(1);
	set_read("You cannot read the letters.\n");
    }
}
