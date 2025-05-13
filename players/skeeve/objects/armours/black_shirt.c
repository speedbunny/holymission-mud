inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("black shirt");
    set_alias("shirt");
    set_type("armour/arm");
    set_value(800);
    set_ac(1);
    set_weight(1);
    set_size(2);
    set_short("A black shirt");
    set_long("This black silken shirt is very fine worked.\n"
    +"The emblem of druid Lakmir embellish it.\n");
  } else if ( !environment(environment(this_object()))) 
    destruct(this_object());
}
