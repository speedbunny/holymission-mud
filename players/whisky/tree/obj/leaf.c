inherit "obj/food";

reset(arg) {
  if(arg) return;
  set_name("leaf");
  set_short("A green leaf");
 set_long("A big green leaf, from the apple tree.\n");
  set_value(2);
  set_weight(1);
  set_eater_mess("Baaaaa that tastes awful.\n");
  set_strength(2);
}
