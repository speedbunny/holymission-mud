inherit "obj/container";  

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Bag of Holding");
  set_alt_name("bag of holding");
  set_alias("bag");
  set_short("A Bag of Holding");
  set_long("This is a small bag, but it holds a lot!\n");
  set_value(100);
  set_weight(2);
  set_max_weight(35);

}
