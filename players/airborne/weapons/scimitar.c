inherit "obj/weapon";

reset(arg){
  ::reset(arg);
  if(arg) return 1;
	set_name("scimitar");
	set_alias("sword");
	set_value(400);
	set_weight(2);
	set_short("Scimitar");
	set_long("Scimitar.  The sword of the desert men.\n");
	set_class(14);
  return 1;
}

