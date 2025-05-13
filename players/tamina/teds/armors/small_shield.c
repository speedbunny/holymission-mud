inherit "obj/armour";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return;

  set_name("small shield");
  set_type("shield");
  set_size(2);
  set_short("A Small Shield");
  set_long("A small leather covered shield.\n");
  set_ac(1);
  set_weight(1);
  set_value(100);
}
