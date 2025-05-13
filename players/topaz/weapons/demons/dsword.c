inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("sword");
  set_short("A demon's sword");
  set_long("This sword seems to be a good weapon.\n");
  set_class(12);
  set_value(1200);
  set_weight(2);
}
