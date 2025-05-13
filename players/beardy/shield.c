inherit "obj/armour";

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_name("shield");

    set_short("a shield");
    set_long("It's a normal test shield\n");

    set_type("guild");
    set_ac(1);
    set_value(400);
    set_weight(1);
  }
}
