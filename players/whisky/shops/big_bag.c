inherit "obj/container";

reset(arg) {

  ::reset(arg);
  if (arg) return;
   set_name("bag");
    set_alias("big bag");
    set_max_weight(10); /* not much but the price is low */
    set_short("A Big Bag");
    set_long("An even more deeper bag.\n");
    set_value(10);
    set_weight(1);
}
