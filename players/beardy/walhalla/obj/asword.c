inherit"obj/weapon";

reset(arg)
{ ::reset(arg);
  if(!arg)
  {
    set_name("sword");
    set_alt_name("sword");
    
    set_short("Hel's sword");
    set_long("This is the famous sword of godess Hel. How did you get it ?\n");
    set_type(2);
    set_class(19);
    set_value(15000);

    set_weight(3);
    
  }
}
