inherit "obj/alco_drink";
 
void reset(int arg) {
// Must call ::reset() first to initialize variables.
  ::reset(arg);
  if(arg) return;
 
  set_name("apple rum");
  set_alias_list(({"rum","liquor","shot"}));
  set_strength(3);
  set_value(15);
  set_drinker_mess("It has a harsh applely taste.\n");
  set_drinking_mess(" drinks a shot of apple rum.\n");
  set_short("A shot of apple rum");
  set_long("This is a generous shot of apple rum. You're not "+
    "sure what it tastes like, but it is liquor.\n"); 
  set_weight(1);
  set_empty_container("vial");
}
