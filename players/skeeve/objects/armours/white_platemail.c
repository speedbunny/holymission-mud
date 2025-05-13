inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("white platemail");
    set_alias("platemail");
    set_type("armour");
    set_value(2000);
    set_ac(4);
    set_weight(5);
    set_size(4);
    set_short("A white platemail");
    set_long("This armour provides good protection against enemies.\n");
  } else if ( !environment(environment(this_object()))) 
    destruct(this_object());
}
