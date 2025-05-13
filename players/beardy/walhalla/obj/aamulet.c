inherit "obj/armour";

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_name("amulet");

    set_short("golden amulet");
    set_long("This is Hel's golden amulet\n");

    set_type("amulet");
    set_ac(2);
    set_value(5000);
    set_weight(1);
  }
}
