inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("head phones");
  set_type("helmet");
  set_ac(0);
  set_short("Head Phones");
set_long("These are a set of loud head phones.\n");
  set_value(150);
  set_weight(2);
  return 1;
}

