inherit "/obj/treasure";

reset(arg) {
  if (arg) return 1;
  set_id("diamond");
  set_short("huge diamond");
  set_long("This jewel was once embedded in the chest of the stone golem, but now it's\nyours. Looks as if it's quite valuable.\n");
  set_value(2000);
  set_weight(1);
  return 1;
}

