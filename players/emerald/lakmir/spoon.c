inherit "/obj/weapon";

reset(arg) {
  ::reset(arg);
  if (!arg){
    set_name("spoon");
    set_short("A wooden spoon");
    set_class(1);
    set_long("A wooden spoon used for stirring.\n");
    set_value(5);
  }
}
