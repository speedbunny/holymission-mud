inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("club");
    set_alias("stone club");
    set_short("A stone club");
    set_long("This is a stone club. It seems very strong.\n");
    set_class(18);
    set_weight(6);
    set_value(2000);
    set_type(1);
  }
}

/* This is a non-metal weapon */

query_non_metal() {
  return 1;
}
