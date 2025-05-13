inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("fur");
    set_alias("fur");
    set_type("armour");
    set_value(1);
    set_ac(1);
    set_weight(1);
    set_size(0);
    set_short("A fur");
    set_long("It's a fine fur.\n");
  } else if ( !environment(environment(this_object()))) 
    destruct(this_object());
}
