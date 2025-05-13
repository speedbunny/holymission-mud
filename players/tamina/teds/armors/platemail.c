inherit "obj/armour";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return;

  set_name("platemail");
  set_type("armour/helmet");
  set_alias("platemail armor");
  set_short("Platemail Armor");
  set_long(
    "This set of hardened steel covers the upper legs, body and arms.\n"+
    "It also provides protection to your head.\n");
  set_ac(5);
  set_weight(9);
  set_value(2000);
}
