inherit "/obj/treasure";

reset(arg) {
  if (arg) return 1;
  set_id("chair");
set_short("chair");
 set_long("This is a hard wooden chair.\n Have a seat!\n");
  set_value(0);
set_weight(10);
  set_info("chair (created by Jake using Uranus' Wand)");
  return 1;
}

query_objmaker() { return 1; }
