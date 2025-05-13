inherit "obj/soft_drink";
 
void reset(int arg) {
  ::reset(arg);
  if(arg) return;
 
  set_name("apple juice");
  set_alias_list(({"juice","fruit juice"}));
  set_strength(3);
  set_value(15);
  set_drinker_mess("Very tasty indeed!\n");
  set_drinking_mess(" drinks some apple juice.\n");
  set_short("A bottle of apple juice");
  set_long("This is a bottle of apple juice. You're almost "+
    "sure it tastes like apples, as most fruit juices have the "+
    "taste of their fruit.\n");
  set_weight(1);
  set_empty_container("bottle");
}
