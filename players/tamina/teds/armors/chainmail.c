inherit "obj/armour";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return;

  set_name("chainmail");
  set_type("armour");
  set_alias("chainmail armour");
  set_short("Chainmail Armour");
  set_long("This suite of chainmail covers the upper body and arms,\n"+
	   "and has a small skirt around the upper legs.\n");
  set_ac(4);
  set_weight(5);
  set_value(1000);
}
