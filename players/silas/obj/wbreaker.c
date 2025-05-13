inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("windbreaker");
  set_type("cloak");
  set_ac(1);
  set_short("Windbreaker");
  set_long("This is a light jacket which once belonged to Erwin. It serves as a modest\nform of protection.\n");
  set_value(500);
  set_weight(1);
  return 1;
}

