inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("trouser suit");
    set_alias("suit");
    set_type("armour/leg/arm");
    set_value(800);
    set_ac(1);
    set_weight(3);
    set_size(2);
    set_short("A trouser suit");
    set_long("This blue trouser suit is made of coarse cotton.\n"
    +"The emblem of druid Lakmir embellish it.\n\n");
  } else if ( !environment(environment(this_object()))) 
    destruct(this_object());
}
