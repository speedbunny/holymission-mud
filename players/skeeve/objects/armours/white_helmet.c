inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("white helmet");
    set_alias("helmet");
    set_type("helmet");
    set_value(400);
    set_ac(1); /* Airborne: Changed questionable AC */
    set_weight(3);
    set_size(4);
    set_short("A white helmet");
    set_long("This helmet provides good protection against enemies.\n");
  } else if ( !environment(environment(this_object()))) 
    destruct(this_object());
}
