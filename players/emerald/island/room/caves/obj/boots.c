inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("fur boots");
  set_short("Fur boots");
  set_alias("boots");
  set_long("Boots made of bear fur.\n");
  set_weight(1);
  set_ac(1);
  set_value(80);
  set_type("boot");

}
