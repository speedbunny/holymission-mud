inherit "/obj/treasure";

reset(arg) {
  if(arg) return;
    set_id("shell");
    set_alias("crab shell");
    set_short("A crab shell");
    set_long("Only a little crab shell.\n");
    set_value(60);
    set_weight(1);
 }
