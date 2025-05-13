inherit "obj/weapon";
reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("guard sword");
  set_alias("sword");
  set_class(21);
  set_value(6000);
  set_weight(10);
  set_short("Guard sword");
  set_long("The sword of the oracle guardian.\n");
}
