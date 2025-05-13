inherit "obj/armour";

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_name("armour");

    set_short("Odin's armour");
    set_long("This is Odin's special armour. It looks very\n" +
             "fine and it glows soft blue.\n");

    set_type("armour");
    set_ac(5);
    set_value(14000);
    set_weight(5);
  }
}
