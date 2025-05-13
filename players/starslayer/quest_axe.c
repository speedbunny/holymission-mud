inherit "obj/weapon";

reset(arg){
   ::reset(arg);
   if (arg) return 1 ;
	set_id("quest_axe");
	set_name("Battle Axe");
	set_short("Battle Axe");
	set_alias("axe");
	set_alt_name("battle axe");
	set_long("A beautiful battle axe. It appears to be made from a strange\n"+"metal. \n");
	set_class(10+(random(8)));
	set_weight(2);
	set_value(2000);
	return 1;
}
