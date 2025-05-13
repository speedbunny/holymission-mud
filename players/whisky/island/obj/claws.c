inherit "/obj/weapon";
 
reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("claws");
  set_class(4);
  set_short("Cancer Claws");
  set_long("The claws from the dangerous wolf\n");
  set_value(25);
  set_weight(1);
}
