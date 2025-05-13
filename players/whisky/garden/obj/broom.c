inherit "obj/weapon";
 
reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("broom");
  set_class(12);
  set_short("A witch broom");
  set_long("The weapon of the evil witch.\n");
  set_value(250);
  set_weight(1);
}
