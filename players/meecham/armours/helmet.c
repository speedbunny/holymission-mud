inherit "obj/armour";
reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("helmet");
  set_type("helmet");
  set_value(50);
  set_ac(1);
  set_weight(1);
  set_short("helmet");
  set_long("A helmet (its for you head)\n");
}
