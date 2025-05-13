inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("black cloak");
    set_alias("cloak");
    set_type("cloak/robe");
    set_value(250);
    set_ac(1);
    set_weight(2);
    set_size(0);
    set_short("A black silken cloak");
    set_long("This black silken cloak is very fine worked.\n"
         +"The emblem of druid Lakmir embellish it.\n");
  } else if ( !environment(environment(this_object()))) 
    destruct(this_object());
}
