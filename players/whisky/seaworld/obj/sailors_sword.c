inherit "/obj/weapon";

reset(arg) {
  ::reset(arg);
if (!arg) { 
    set_name("sword");
    set_class(12);
    set_alias("sailors sword");
    set_short("A sailors sword");
    set_long("The good weapon of the drunken sailor.\n");
    set_type(2);
    set_value(400);
    set_weight(2);
  }
}
