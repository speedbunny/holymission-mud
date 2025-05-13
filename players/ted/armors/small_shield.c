inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("small shield");
  set_type("shield");
  set_alias("shield");
  set_size("small");
  set_short("A Small Shield");
  set_long("A small leather covered shield.\n");
  set_ac(1);
  set_weight(1);
  set_value(50);
}
