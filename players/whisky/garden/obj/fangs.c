inherit "obj/weapon";

reset (arg) {

  ::reset(arg);
  if (!arg) {
     set_name("fangs");
     set_alias("tarantula fangs");
     set_short("Big Tarantula Fangs");
     set_long("The weapon from the big black Spider.\n");
     set_type(2);
     set_weight(1);
     set_value(100);
     set_class(8);
  }
}
