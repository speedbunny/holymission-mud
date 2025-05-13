inherit "/obj/weapon";
 
reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("claws");
  set_alias("grabbit claws");
  set_class(17);
  set_short("Grabbit claws");
  set_long("The sharp claws of a Giant grabbit.\n");
  set_value(700);
  set_weight(2);
}
