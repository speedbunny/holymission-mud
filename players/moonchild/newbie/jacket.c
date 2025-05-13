inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  set_name("jacket");
  set_type("armour");
  set_short("A leather jacket");
  set_long("This is a rather rough and ready leather jacket.\n");
  set_ac(1+random(2));
  set_weight(ac);
}

drop() {
  tell_object(environment(), "The jacket suddenly falls to pieces.\n");
  destruct(this_object());
  return 1;
}
