inherit "obj/armour"; 

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("Leather Boots");
 set_alias("leather boots");
 set_type("boots");
 set_size("medium");
 set_short("Soft Leather Boots");
 set_long("These soft leather boots come up to about mid-thigh.\n");
 set_ac(1);
 set_weight(1);
 set_value(200);
}
