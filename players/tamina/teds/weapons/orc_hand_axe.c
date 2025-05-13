inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("hand axe");
  set_alias("axe");
  set_short("A Hand Axe");
  set_class(10);
  set_weight(2);
  set_value(75);
}
