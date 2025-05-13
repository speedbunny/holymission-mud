inherit "obj/armour";

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_name("cloak");

    set_short("golden cloak");
    set_long("It's Hel's golden cloak.\n");

    set_type("cloak");
    set_ac(1);
    set_value(600);
    set_weight(1);
  }
}
