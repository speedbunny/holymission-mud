inherit "obj/armour";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return;

  set_name("Amulet of Protection");
  set_type("amulet");
  set_alias("amulet of protection");
  set_size(0);
  set_short("An Amulet of Protection");
  set_long("This amulet projects some type of invisible shield around you.\n");
  set_ac(1);
  set_weight(2);
  set_value(800);
}
