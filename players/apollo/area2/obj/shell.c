inherit "/obj/treasure";

reset(arg) {
  if(arg) return;
    set_id("shell");
    set_alias("big shell");
    set_short("A big shell");
    set_long("A big brown shell.\n");
    set_value(80);
    set_weight(1);
 }
