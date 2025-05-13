inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("War Spear");
  set_alias("spear");
  set_alt_name("war spear");
  set_short("A Short War Spear");
  set_long("This gold inlayed spear is set with gems and precious stones.\n");
  set_class(16);
  set_value(1500);
  set_weight(4);
}
