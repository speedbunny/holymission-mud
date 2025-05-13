inherit "/obj/armour";

reset(arg){
	::reset(arg);
	if(arg) return 1;
	set_name("double mail");
	set_type("armour");
	set_alias("mail");
	set_size(4);
	set_weight(6);
	set_ac(3);
	set_value(2000);
	set_short("Double Mail");
	set_long("A suit of double mail.\n");
   return 1;
}
