inherit "obj/armour";
reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("diamond shield");
  set_type("shield");
  set_alias("shield");
  set_ac(2);
  set_weight(2);
  set_value(2000);
  set_short("diamond shield");
  set_long("Coldrik's diamond shield offers magnificent protection.\n");
}
