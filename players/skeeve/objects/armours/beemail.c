inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("beemail");
    set_alias("beemail");
    set_type("armour/helmet/arm/glove/leg/boot/robe");
    set_value(1200);
    set_ac(3);
    set_weight(4);
    set_size(0);
    set_short("A beemail");
    set_long("This mail is a full body protection against bees.\n"
    +"The emblem of druid Lakmir embellish it.\n");
  } else if ( !environment(environment(this_object()))) 
    destruct(this_object());
}
