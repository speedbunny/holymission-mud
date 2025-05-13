inherit "obj/weapon";

reset(arg) {
	if(arg) return 1;
	set_name("maul");
	set_alias("earbiter");
	set_short("Earbiter");
	set_long("This is Earbiter, Syth's deadly maul.\n" +"Handle with care!\n");
	set_class(15 + random(5));
	set_weight(5);
	set_value(3000);
}
