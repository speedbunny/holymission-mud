inherit "/obj/weapon";
 
reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("claws");
  set_class(8);
  set_short("Wolf Claws");
  set_long("The claws from the dangerous wolf\n");
  set_value(50);
  set_weight(1);
}
