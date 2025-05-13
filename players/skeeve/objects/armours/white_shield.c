inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("white shield");
    set_alias("shield");
    set_type("shield");
    set_value(350);
    set_ac(1); /* Airborne: Lowered the questionable AC */
    set_weight(3);
    set_size(4);
    set_short("A white iron shield");
    set_long("This heavy shield provides good protection against enemies.\n"
    +"The emblem of druid Lakmir embellish it.\n");
  } else if ( !environment(environment(this_object()))) 
    destruct(this_object());
}
