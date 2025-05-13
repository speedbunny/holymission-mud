inherit "obj/container";

void reset(int arg) 
{
  ::reset(arg);	
  if(arg) return 0;

  set_name("leather sack");
  set_alias("sack");
  set_short("A Large Leather Sack");
  set_long("A large sturdy leather sack.\n");
  set_value(15);
  set_weight(2);
  set_max_weight(12);
}
