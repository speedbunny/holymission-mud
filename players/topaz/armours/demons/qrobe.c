inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("robe");
  set_short("An exquisite white robe");
  set_long("An expensive looking white robe.\n");
  set_type("robe");
  set_ac(1);
  set_weight(2);
  set_value(1500);
}
