inherit "obj/weapon";
 
reset(arg) {
	::reset(arg);
	if(arg) return 1;
	set_name("katana");
	set_alias("sword");
	set_class(12);
	set_value(550);
	set_short("Katana sword");
	set_long("This is a razor sharp katana sword used by Xiang Jiao.\n");
	set_weight (2);
   return 1;
}
