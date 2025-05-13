inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("short sword");
  set_short("A Short Sword");
  set_class(10);
  set_weight(2);
  set_value(75);
}
