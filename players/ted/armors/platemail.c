inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("platemail");
  set_type("armor");
  set_alias("platemail armor");
  set_short("Platemail Armor");
  set_long("This set of hardened steel covers the upper legs, body and arms.\n");
  set_ac(5);
  set_weight(9);
  set_value(1000);
}
