inherit "/obj/armour";


reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("cloak");
  set_alias("cloak");
  set_short("A flowing, multi-coloured cloak");
  set_long("This is obviously a stage cloak of some kind.\n");
  set_type("cloak");
  set_ac(1);
  set_weight(1);
  set_value(100);
}


