inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Shield of Light");
  set_type("shield");
  set_alias("shield of light");
  set_short("A Shield of Light");
  set_long("This shield shines brightly with it's own inner radiance.\n");
  set_ac(2);
  set_weight(2);
  set_value(500);
  set_light(1);
}
