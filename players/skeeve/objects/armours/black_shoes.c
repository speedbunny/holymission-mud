inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("black shoes");
    set_alias("shoes");
    set_type("boot");
    set_value(250);
    set_ac(1);
    set_weight(1);
    set_size(2);
    set_short("A pair of black shoes");
    set_long("This black silken shoes are very fine worked.\n");
  } else if ( !environment(environment(this_object()))) 
    destruct(this_object());
}
