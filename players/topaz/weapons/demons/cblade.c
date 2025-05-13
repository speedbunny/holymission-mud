inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("blade");
  set_short("A ceremonial blade");
  set_long("This blade looks like it has a very evil purpose!\n");
  set_class(12);
  set_value(1200);
  set_weight(2);
}
