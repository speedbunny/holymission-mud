inherit "obj/armour";
reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("demon cloak");
  set_type("cloak");
  set_ac(1);
  set_weight(1);
  set_value(1000);
   set_short("demon cloak");
  set_long("This is black cloak of one of Coldrik's demon guards.\n");
}
