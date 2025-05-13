inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Leather Armor");
  set_type("armor");
  set_alias("leather armor");
  set_short("A Suite of Leather Armor");
  set_long("This armor covers the upper body and arms.\n");
  set_ac(2);
  set_weight(2);
  set_value(50);
}
