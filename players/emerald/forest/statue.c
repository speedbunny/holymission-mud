inherit "/obj/thing";
void reset(int arg) {
  ::reset(arg);
  if(arg) return;
    set_name("stone statue");
    set_alias("statue");
    set_short("A stone statue");
    set_long("A stone statue of a Baaz draconian.\n");
    set_weight(25);
    set_value(200);
    set_can_get(1);
}

