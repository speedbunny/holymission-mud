inherit "obj/armour";

reset(arg){
  ::reset(arg);
  if(arg) return 1;
	set_name("helmet");
	set_type("helmet");
	set_ac(1);
	set_value(50);
	set_short("Dark helmet");
	set_long("A helmet made from a darkened metal.\n");
   return 1;
	}
