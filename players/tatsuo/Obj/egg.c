inherit "obj/food";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("roc egg");
  set_alias("egg");
  set_short(query_name());
  set_long("The giantic egg of a roc bird.\n");
  set_value(130);
  set_weight(2);
  set_heal_amount(65);
  set_strength(5);
}
