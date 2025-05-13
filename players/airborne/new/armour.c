inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  set_name("padded");
  set_type("armour");
  set_short("Padded armour");
  set_long("A comfortable suit of padded armour.\n");
  set_ac(1+random(2));
  set_weight(ac);
}

drop() {
  tell_object(environment(), "The armour suddenly falls to pieces.\n");
  destruct(this_object());
  return 1;
}
