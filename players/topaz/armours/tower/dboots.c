inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("boots");
  set_short("Dirty boots");
  set_long("Dirty boots that are still good armour.\n");
  set_type("boot");
  set_ac(1);
  set_weight(1);
  set_value(100);
}
