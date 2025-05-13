inherit "obj/treasure";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return 0;

  set_id("key");
  set_name("key");
  set_alias("frost_key");
  set_short("A White Key");
  set_weight(1);
  set_value(100);
}
