inherit "/obj/weapon";

reset(arg) {
  ::reset(arg);
  if (!arg) { 
    set_name("saw");
    set_class(14);
    set_alias("sawfish saw");
    set_short("The sawfish saw");
    set_long("The strong weapon of the evil sawfish.\n");
    set_type(1);
    set_value(800);
    set_weight(2);
  }
 }
