inherit "/obj/treasure";

reset(arg) {
  if (arg) return 1;
  set_id("fire key");
  set_short("Fire key");
set_long("This is a fire key.\nIt doesn't open aything. [yet]\n");
  set_value(10);
  set_weight(1);
  set_info("fire key (created by Someone using Uranus' Wand)");
  return 1;
}

query_objmaker() { return 1; }

