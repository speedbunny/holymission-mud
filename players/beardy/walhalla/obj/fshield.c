inherit "obj/armour";

reset(arg)
{ ::reset(arg);
  if(!arg)
  {
    set_name("shield");

    set_short("fish shield");
    set_long("It's a shield made out of fishes.\n");
    set_type("shield");
    set_ac(1);
    set_value(400);
    set_weight(1);
  }
}
