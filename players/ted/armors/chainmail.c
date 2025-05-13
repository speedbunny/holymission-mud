inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("chainmail");
  set_type("armor");
  set_alias("chainmail armor");
  set_short("Chainmail Armor");
  set_long("This suite of chainmail covers the upper body and arms.\n");
  set_ac(4);
  set_weight(5);
  set_value(500);
}
