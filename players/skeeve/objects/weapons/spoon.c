inherit "/obj/weapon";

reset(arg) {
  ::reset(arg);
  if (!arg){
    set_name("spoon");
    set_short("A wooden spoon");
    set_class(1);
    set_long("The cook use this simple wooden spoon to stir in the kettle.\n");
    set_value(5);
  } else {
    if (!environment(environment(this_object()))) destruct(this_object());
  }
}
