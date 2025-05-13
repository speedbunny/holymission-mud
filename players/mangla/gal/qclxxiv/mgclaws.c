inherit "/obj/weapon";
 
reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("claws");
  set_alias("grabbit claws");
  set_class(7);
  set_short("grabbit claws");
  set_long("The claws of a medium grabbit.\n");
  set_value(70);
  set_weight(1);
}
