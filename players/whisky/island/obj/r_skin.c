inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("dragonskin");
    set_alias("skin");
    set_type("armour");
    set_ac(4);
    set_size(4);
    set_short("A red dragonskin");
    set_long("The excellent armour of\n"+
             "the red volcano Dragon.\n");
    set_value(3000);
    set_weight(3); /* for that value (whisky) */
  }
}
