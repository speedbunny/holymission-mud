inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("white gauntlets");
    set_alias("gauntlets");
    set_type("glove");
    set_value(250);
    set_ac(1);
    set_weight(2);
    set_size(4);
    set_short("A pair of white iron gauntlets");
    set_long("This gauntlets provides good protection against enemies.\n");
  } else if ( !environment(environment(this_object()))) 
    destruct(this_object());
}
