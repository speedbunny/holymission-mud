inherit "obj/weapon";

reset(arg) {
	::reset(arg);
	if(arg) return 1;
	set_name("mace");
	set_short("A mace");
	set_long("A troll sized mace.\n");
	set_class(13);
	set_value(500);
	set_weight(3);
   return 1;
}
