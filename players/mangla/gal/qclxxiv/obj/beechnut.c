inherit "obj/food";
reset(arg) {
  if(arg) return;
  set_name("beechnut");
  set_short("a crispy beechnut");
  set_long("It looks crispy and tasty.\n");
  set_value(2);
  set_weight(1);
  set_eater_mess("You nibble on a crispy and tasty beechnut. Mjum mjum.\n");
  set_strength(3);
}
