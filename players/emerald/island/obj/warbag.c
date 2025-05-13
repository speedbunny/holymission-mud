inherit "obj/armour";
void reset(int arg) {
  ::reset(arg);
  if (arg) return;

  set_name("warbag");
  set_alias("gnomish warbag");
  set_short("a gnomish warbag");
  set_long("The gnomish warbag is small, and made of extremely tough "+
           "leather.  Three holes are cut in it, big enough to stick your "+
           "head and arms through so that it can be worn as an armour.\n");
  set_type("armour");
  set_ac(3);
  set_weight(2);
  set_value(100);
  set_size(3);
}
