inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("Fire Giant Shield");
 set_alias("fire giant shield");
 set_type("shield");
 set_size("large");
 set_short("A Fire Giant Shield");
 set_long("This is a huge red shield. Crude, but effective.\n");
 set_ac(2);
 set_weight(3);
 set_value(100);
}
