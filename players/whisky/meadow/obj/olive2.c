inherit "obj/food";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("olive");
  set_short("A big pressed olive");
  set_long("It looks dry, as if somebody had pressed the oil out of it.\n");
  set_value(2);
  set_weight(1);
  set_eater_mess("Mhhhhh tastes a bit dry but fine.\n"); 
  set_strength(1);
}

