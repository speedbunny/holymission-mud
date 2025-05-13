inherit "obj/armour";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return;

  set_name("Wool Cloak");
  set_type("cloak");
  set_alias("wool cloak");
  set_short("A Heavy Wool Cloak");
  set_long("This cloak looks like it might provide some protection.\n");
  set_ac(1);
  set_weight(2);
  set_value(200);
}
