inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    if (!arg) {
      set_name("dress");
      set_short("A red dress");
      set_long("It's a very nice red dress.\n");
      set_value(15);
        set_weight(1);
      set_ac(1);
      set_type("armour");
      set_size(2);
    }
}

get() {
  return 1;
}

query_plural() {
  return("dresses");
}
