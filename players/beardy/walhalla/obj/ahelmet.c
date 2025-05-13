inherit "obj/armour";

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_name("helmet");

    set_short("golden helmet");
    set_long("It's Hel's golden helmet.\n");

    set_type("helmet");
    set_ac(2);
    set_value(800);
    set_weight(1);
  }
}
