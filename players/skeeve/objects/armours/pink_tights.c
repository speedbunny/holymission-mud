inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("pink tights");
    set_alias("tights");
    set_type("leg");
    set_value(260);
    set_ac(0); /* Airborne: Not valid type for AC */
    set_weight(1);
    set_size(3);
    set_short("A pair of pink tights");
    set_long("This pink tights are made of very fine pink silk.\n");
  } else if ( !environment(environment(this_object()))) 
    destruct(this_object());
}
