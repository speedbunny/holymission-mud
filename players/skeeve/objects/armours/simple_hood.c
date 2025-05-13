inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("simple hood");
    set_alias("hood");
    set_type("helmet");
    set_value(50);
    set_ac(0);
    set_weight(1);
    set_size(0);
    set_short("A simple hood");
    set_long("You wonder, what kind of peoples wants to carry such a hood.\n");
  } else if ( !environment(environment(this_object()))) 
    destruct(this_object());
}
