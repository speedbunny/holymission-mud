inherit "obj/container";  

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return 0;

  set_name("Bag of Holding");
  set_alt_name("bag of holding");
  set_alias("bag");
  set_short("A Bag of Holding");
  set_long("This is a small bag, but it holds a lot!\n");
  set_value(40);
  set_weight(2);
  set_max_weight(21);
}
