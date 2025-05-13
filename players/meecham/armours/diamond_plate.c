inherit "obj/armour";
reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("diamond platemail");
  set_type("armour");
  set_alias("platemail");
  set_ac(6);
  set_weight(5);
  set_value(10000);
  set_short("diamond platemail");
  set_long("The diamonds sparkle brilliantly as you recall that the diamond\n"+
"is the hardest rock known to man.\n");
}
