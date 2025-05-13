inherit"obj/weapon";

reset(arg)
{ ::reset(arg);
  if(!arg)
  {
    set_name("sword");
    set_alt_name("sword");

    
    set_short("Wotan's sword");
    set_long("This is Wotans private sword. He is very unhappy,\n" +
             "because you took it away from him. Perhaps you should\n" +
             "return it to him before he returns...\n");

    set_class(18);
    set_value(13000);

    set_weight(2);
    
  }
}
