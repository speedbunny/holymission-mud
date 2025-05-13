inherit "obj/armour";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return;

  set_name("shield");
  set_type("shield");
  set_size(3);
  set_short("A Medium Shield");
  set_long("A metal shield covered with leather.\n");
  set_ac(1);
  set_weight(2);
  set_value(150);
}
