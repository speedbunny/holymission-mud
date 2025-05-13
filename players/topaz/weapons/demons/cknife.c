inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("knife");
  set_short("A ceremonial knife");
  set_long("This knife looks like it has an evil purpose!\n");
  set_class(9);
  set_value(750);
  set_weight(1);
}
