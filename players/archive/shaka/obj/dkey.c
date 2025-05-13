inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("key");
  set_alias("unlocker");
  set_short("A skeleton key");
  set_long("A key made out of a human skull.\n");
  set_weight(1);
  set_value(20);
}

