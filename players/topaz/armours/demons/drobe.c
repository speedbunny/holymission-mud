inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("robe");
  set_short("A soft black robe");
  set_long("A soft black robe that is very pretty.\n");
  set_type("robe");
  set_ac(1);
  set_weight(2);
  set_value(750);
}
