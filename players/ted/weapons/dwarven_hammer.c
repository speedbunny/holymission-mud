inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("dwarven hammer");
  set_alias("hammer");
  set_short("A Dwarven Hammer");
  set_class(10);
  set_weight(2);
  set_value(75);
}
