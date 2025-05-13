inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("A tie");
    set_alias("tie");
    set_type("neck");
    set_value(210);
    set_weight(1);
    set_ac(1);
    set_short("A bright yellow tie");
    set_long("A yellow tie which belonged to one of Jabba's dinner guests.\n");
  } 
}
