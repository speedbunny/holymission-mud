inherit "obj/armour";
reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("chainmail");
  set_ac(3);
  set_weight(3);
  set_value(150);
  set_short("A suit of chainmail");
  set_long("This chainmail will give adequate protection.\n");
}
