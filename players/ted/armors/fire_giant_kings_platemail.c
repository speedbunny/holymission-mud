inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("Fire Giant King's Platemail");
 set_alias("platemail");
 set_type("armor");
 set_size("large");
 set_short("Fire Giant King's Platemail");
 set_long(
"This armor is made of a very light but strong metal. The redish\n"+
"tint almost reminds you of dried blood......\n");
 set_ac(6);
 set_weight(6);
 set_value(6500);
 set_arm_light(1);
}
