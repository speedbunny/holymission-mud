inherit "obj/armour"; 

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return;

  set_name("leather boots");
  set_alias("boots");
  set_type("boots");
  set_size(3);
  set_short("Soft Leather Boots");
  set_long("These soft leather boots come up to about mid-thigh.\n");
  set_ac(1);
  set_weight(1);
  set_value(200);
}
