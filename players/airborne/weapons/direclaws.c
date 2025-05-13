inherit "obj/weapon";

reset(arg){
	::reset(arg);
	if(arg) return 1;
   set_name("dire harpy claws");
   set_alias("claws");
   set_class(12);
   set_short("Dire Harpy Claws");
   set_long("The actual claws from the devilish dire harpy!\n");
   set_value(400);
   set_weight(2);
	return 1;
}
