inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("gloves");
  set_type("glove");
  set_ac(1);
  set_short("Leather Gloves");
  set_long("A pair of leather gloves, worn but sturdy.\n");
  set_value(250);
  set_weight(1);
  return 1;
}

