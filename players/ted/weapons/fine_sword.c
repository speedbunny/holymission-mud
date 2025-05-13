 inherit "obj/weapon"; 

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Fine Sword");
  set_alias("sword");
  set_short("A Fine Sword");
  set_long("This gold inlayed sword is set with gems and precious stones.\n");
  set_class(16);
  set_value(1750);
  set_weight(4);
}
