inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("dragonskin");
    set_alias("skin");
    set_type("armour");
    set_ac(4);
    set_size(3);
    set_short("A green dragonskin");
    set_long("The excellent armour of\n"+
             "the green volcano Dragon.\n");
    set_value(1000);
    set_weight(2); /* for that value (whisky) */
  }
}
