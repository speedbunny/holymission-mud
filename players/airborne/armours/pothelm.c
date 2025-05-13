inherit "obj/armour";
  reset(arg){
  ::reset(arg);
  if(arg) return 1;
	set_type("helmet");
	set_name("pot");
	set_alias("cooking pot");
	set_size(2);
	set_weight(1);
	set_value(10);
	set_ac(0);
	set_short("Cooking pot");
	set_long("A cooking pot with the small bits of stew.\n"+"You might be able to wear it.\n");
  return 1;
	}
