inherit "obj/armour";

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_name("gloves");

    set_short("battle gloves");
    set_long("This are the battlegloves of Hel.\n");

    set_type("glove");
    set_ac(1);
    set_value(500);
    set_weight(1);
  }
}
