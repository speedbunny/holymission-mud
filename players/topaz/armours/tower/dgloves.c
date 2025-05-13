inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("gloves");
  set_short("Leather gloves");
  set_long("Leather gloves, toughened by much use.\n");
  set_type("glove");
  set_ac(1);
  set_weight(1);
  set_value(500);
}
