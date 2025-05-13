inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("dragonskin");
    set_alias("skin");
    set_type("armour");
    set_ac(3);
    set_size(2);
    set_short("A baby dragonskin");
    set_long("The armour of the cute\n"+
             "the baby Dragon.\n");
    set_value(400);
    set_weight(1); /* for that value (whisky) */
  }
}
