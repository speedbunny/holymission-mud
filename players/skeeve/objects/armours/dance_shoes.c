inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("dance shoes");
    set_alias("shoes");
    set_type("boot");
    set_value(320);
    set_ac(1);
    set_weight(1);
    set_size(3);
    set_short("A pair of dance shoes");
    set_long("This pink, silken shoes are perfect for a danseuse.\n");
  } else if ( !environment(environment(this_object()))) 
    destruct(this_object());
}
