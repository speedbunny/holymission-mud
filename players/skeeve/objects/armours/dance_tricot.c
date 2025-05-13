inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("dance tricot");
    set_alias("tricot");
    set_type("armour/arm");
    set_value(200);
    set_ac(1); /* Airborne: Arm not valid for AC. */
    set_weight(2);
    set_size(3);
    set_short("A dance tricot");
    set_long("It's a pink tricot with fine lace.\n");
  } else if ( !environment(environment(this_object()))) 
    destruct(this_object());
}
