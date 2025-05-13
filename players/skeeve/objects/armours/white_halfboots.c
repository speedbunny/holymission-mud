inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("white halfboots");
    set_alias("halfboots");
    set_type("boot");
    set_value(400);
    set_ac(1); /* Airborne: Lowered questionable AC */
    set_weight(3);
    set_size(4);
    set_short("A pair of white iron halfboots");
    set_long("This halfboots provides good protection against enemies.\n");
  } else if ( !environment(environment(this_object()))) 
    destruct(this_object());
}
