inherit "obj/armour"; 

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("Frost Giant Shield");
 set_alias("frost giant shield");
 set_type("shield");
 set_size("large");
 set_short("A Frost Giant Shield");
 set_long("This is a huge white shield. Crude, but effective.\n");
 set_ac(1);
 set_weight(3);
 set_value(100);
}
