inherit "/obj/treasure";

reset(arg) {
  if (arg) return 1;
  set_id("plume");
  set_short("red plume");
  set_long("A bhuge red feather - you wonder what bird it could\n"+ 
  "have come from.\n");
  set_value(3000);
  set_weight(2);
  return 1;
}

