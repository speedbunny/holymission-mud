inherit "obj/armour";
reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("Elven platemail");
  set_id("platemail");
  set_type("armour");
  set_value(3000);
  set_ac(4);
  set_weight(5);
  set_short("elven platemail");
  set_long("This is finely crafted elven platemail.\n");
}
