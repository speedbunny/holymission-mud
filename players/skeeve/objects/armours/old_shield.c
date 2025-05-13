inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("old shield");
    set_alias("white shield");
    set_type("shield");
    set_value(150);
    set_ac(1);
    set_weight(4);
    set_size(0);
    set_short("A white iron shield");
    set_long("Long time before this heavy shield provides good protection against enemies.\n"
         +"Now it's dirty and injured.\n");
  } else if ( !environment(environment(this_object()))) 
    destruct(this_object());
}
