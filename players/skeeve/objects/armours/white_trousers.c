inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("white trousers");
    set_alias("trousers");
    set_type("leg");
    set_value(150);
    set_ac(0); /* Airborne: Invalid type for ac. */
    set_weight(1);
    set_size(4);
    set_short("A pair of white leather trousers");
    set_long("This trousers are made of very fine white leather.\n");
  } else if ( !environment(environment(this_object()))) 
    destruct(this_object());
}
