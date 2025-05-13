inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("shield");
  set_type("shield");
  set_alias("medium shield");
  set_size("medium");
  set_short("A Medium Shield");
  set_long("A metal shield covered with leather.\n");
  set_ac(2);
  set_weight(2);
  set_value(110);
}
