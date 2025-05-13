inherit "obj/armour";
reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("guard platemail");
  set_id("platemail");
  set_type("armour");
  set_value(5000);
  set_ac(6);
  set_weight(10);
  set_short("Guard platemail");
   set_long("This is the platemail of the oracle guardian.\n");
}
