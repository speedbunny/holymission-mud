inherit "obj/armour";

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_name("plate");

    set_short("Wotan's platemail");
    set_long("It's Wotan's private platemail and i looks\n" +
             "really nice with it blood spills, cuts etc..\n");

    set_type("armour");
    set_ac(4);
    set_value(6000);
    set_weight(5);
  }
}
