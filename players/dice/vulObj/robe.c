inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("robe");
  set_type("armour");
  set_ac(1);
 set_short("An old greek robe");
  set_long("This is an old grey-white robe.\n"+
     "Only real wise man are allowed to wear it.\n");
  set_value(1000);
  set_weight(1);
  return 1;
}

