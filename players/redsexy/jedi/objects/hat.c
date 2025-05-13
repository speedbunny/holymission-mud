inherit "/obj/armour";


reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("hat");
  set_alias("hat");
  set_short("A blue velvet hat");
  set_long("This is obviously a stage hat of some kind.\n");
  set_type("helmet");
  set_ac(1);
  set_weight(1);
  set_value(100);
}


