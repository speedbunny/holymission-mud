inherit "/obj/thing";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("key");
  set_short("A skeleton key");
  set_long("A skeleton key.  You wonder where it fits.\n");
  set_weight(1);
  set_alias("skeleton key");
  set_alt_name("ob1");
  set_value(5);
}
