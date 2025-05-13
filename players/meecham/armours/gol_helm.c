inherit "obj/armour";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("Goliath's helm");
  set_ac(1);
  set_weight(1);
  set_value(1000);
  set_alias("helm");
  set_type("helmet");
  set_short("Goliath's helm");
  set_long("This is the helm of the Nordel God, Goliath.\n");
}
