inherit "obj/armour";
reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("boots");
  set_ac(1);
  set_weight(4);
  set_value(5000);
  set_short("Snow boots");
  set_alias("snow boots");
  set_long("These boots are heavy and built for snow travel.\n");
  set_type("boots");
}
 
