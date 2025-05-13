inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("ice shield");
set_type("shield");
  set_ac(1);
  set_short("Ice shield");
  set_long("This is an ice shield.  It is made entirely of ice.\n");
  set_value(200);
  set_weight(2);
  set_info("ice shield (created by Someone using Uranus' Wand)");
  return 1;
}

query_objmaker() { return 1; }
