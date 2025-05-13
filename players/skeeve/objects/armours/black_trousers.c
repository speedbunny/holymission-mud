inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("black trousers");
    set_alias("trousers");
    set_type("leg");
    set_value(300);
    set_ac(0); /* Airborne: Leg not valid AC type. */
    set_weight(1);
    set_size(2);
    set_short("A pair of black silken trousers");
    set_long("This black silken trousers are very fine worked.\n"
    +"The emblem of druid Lakmir embellish it.\n\n");
  } else if ( !environment(environment(this_object()))) 
    destruct(this_object());
}
