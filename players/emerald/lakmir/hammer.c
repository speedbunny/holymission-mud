inherit "/obj/weapon";
reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("skeleton hammer");
    set_alias("hammer");
    set_class(10);
    set_weight(3);
    set_short("A heavy hammer");
    set_long("The weapon of the skeleton.\n");
    set_value(500);
  }  
}
