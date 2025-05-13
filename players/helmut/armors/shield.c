inherit "obj/armour";

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_name("shield");

    set_short("golden shield");
    set_long("It's a divine shield surrounded by a golden aurea.\n");

    set_type("shield");
    set_ac(1);
    set_value(400);
    set_weight(1);
  }
}
