inherit"obj/weapon";

reset(arg)
{ ::reset(arg);
  if(!arg)
  {
    set_name("sword");
    set_alt_name("sword");
    
   set_short("sword");
    set_long("This is a normal guard sword (= nothing special).\n");
    set_type(2);
    set_class(6);
    set_value(150);

    set_weight(1);
    
  }
}
