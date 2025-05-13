inherit "obj/armour";

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_name("boots");

    set_short("hermes' combat boots");
    set_long("They look very strong.\n");

    set_type("boots");
    set_ac(1);
    set_value(300);
    set_weight(1);
  }
}
