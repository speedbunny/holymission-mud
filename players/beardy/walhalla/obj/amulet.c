inherit "obj/armour";

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_name("amulet");

    set_short("divine amulet");
    set_long("It's a divine amulet, every god should have.\n");

    set_type("amulet");
    set_ac(1);
    set_value(3000);
    set_weight(1);
  }
}
