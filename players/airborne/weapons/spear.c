inherit "obj/weapon";

reset(arg) {
	::reset(arg);
	if(arg) return 1;
	set_name("spear");
	set_class(8);
	set_value(45);
	set_weight(2);
	set_short("A spear");
set_long("A spear from the lizardmen.\n");
   return 1;
}
