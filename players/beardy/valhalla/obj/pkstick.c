inherit "obj/thing";

reset(arg)
{ ::reset(arg);
  if(arg) return 0;
  set_name("piece");
  set_alias("piece of wood");

  set_short("a piece of wood");
  set_long("There are several cuts :\n"+
           "IIIIIIIIIIIIIIIIIII\n"+
	   "\nOne for every player.\n");

  set_value(50);
  set_weight(1);
}
