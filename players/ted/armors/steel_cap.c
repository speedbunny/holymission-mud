inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("steel cap");
  set_type("helmet");
  set_alias("cap");
  set_short("A Steel Cap");
  set_long("This steel cap covers the top of the head and the ears.\n");
  set_ac(1);
  set_weight(1);
  set_value(80);
}
