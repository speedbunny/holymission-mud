inherit"obj/weapon";

reset(arg)
{ ::reset(arg);
  if(!arg)
  {
    set_name("knife");
    set_alt_name("knife");

    
    set_short("a knife");
    set_long("It's a simple knife.\n");

    set_class(2);
    set_value(400);

    set_weight(1);
    
  }
}
