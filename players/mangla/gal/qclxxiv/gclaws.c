inherit "/obj/weapon";
 
reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("claws");
  set_alias("grabbit claws");
  set_class(10);
  set_short("Grabbit claws");
  set_long("The claws of a large grabbit.\n");
  set_value(100);
  set_weight(1);
}
