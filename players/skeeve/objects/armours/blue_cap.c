inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("blue cap");
    set_alias("cap");
    set_type("helmet");
    set_value(40);
    set_ac(0);
    set_weight(1);
    set_size(2);
    set_short("A blue cap");
    set_long("This blue cap is made of cotton and has a peak at the front.\n");
  } else if ( !environment(environment(this_object()))) 
    destruct(this_object());
}
