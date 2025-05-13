inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("chainmail");
  set_short("Demon chainmail");
  set_long("A set of old-looking demon chainmail.\n");
  set_alias("chain");
  set_type("armour");
  set_ac(3);
  set_weight(3);
  set_value(1000);
}
