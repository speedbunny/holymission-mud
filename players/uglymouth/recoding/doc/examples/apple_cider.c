inherit "obj/alco_drink";
 
void reset(int arg) {
// Must call ::reset() first to initialize variables.
  ::reset(arg);
  if(arg) return;
 
  set_name("apple cider");
  set_alias_list(({"cider","liquor","glass"}));
  set_strength(3);
  set_value(15);
  set_drinker_mess("You drink the cider, and then realise it must've "+
                   "been poisoned.\n");
  set_drinking_mess(" drinks a glass of apple cider.\n");
  set_short("A glass of apple cider");
  set_long("This is a generous glass of apple cider. You're "+
    "almost positive it tastes like apples. In fact, there "+
    "are even pieces of apple floating in it.\n");
  set_food(1);
  set_poison(6);
  set_weight(1);
  set_empty_container("glass");
}
