inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("pink shawl");
    set_alias("shawl");
    set_type("cloak");
    set_value(300);
    set_ac(1);
    set_weight(1);
    set_size(0);
    set_short("A pink shawl");
    set_long("This shawl is made of fine pink silk."
    +" The emblem of druid Lakmir embellish it.\n");
  } else if ( !environment(environment(this_object()))) 
    destruct(this_object());
}
