inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("white cloak");
    set_alias("cloak");
    set_type("cloak");
    set_value(150);
    set_ac(1);
    set_weight(1);
    set_size(0);
    set_short("A white leather cloak");
    set_long("This cloak is made of very expensive white leather.\n"
    +"The emblem of druid Lakmir embellish it.\n");
  } else if ( !environment(environment(this_object()))) 
    destruct(this_object());
}
