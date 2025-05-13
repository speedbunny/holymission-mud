inherit "obj/armour";
reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("shield");
  set_type("shield");
  set_ac(1);
  set_value(75);
  set_weight(2);
  set_short("shield");
  set_long("A nice-looking shield.\n");
}

