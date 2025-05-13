inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("white wristlets");
    set_alias("wristlets");
    set_type("arm");
    set_value(200);
    set_ac(0); /* Airborne: Not valid type for AC */
    set_weight(1);
    set_size(0);
    set_short("A pair of white leather wristlets");
    set_long("This pair of wristlets are made of white leather.\n");
  } else if ( !environment(environment(this_object()))) 
    destruct(this_object());
}
