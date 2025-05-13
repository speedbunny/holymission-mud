inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("janitor's mop");
  set_short("A heavy mop");
  set_long("This mop might hurt if you knew how to use it right.\n");
  set_alt_name("janitor's mop");
  set_alias("mop");
  set_class(13);
  set_value(1500);
  set_weight(3);
}
