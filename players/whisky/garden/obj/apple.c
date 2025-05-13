inherit "obj/food";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("apple");
  set_short("a delicious red apple");
  set_long("It looks very big and tasty.\n");
  set_value(2);
  set_weight(1);
  set_eater_mess("You feel the sweet taste of the apple on your tongue. " +
		 "Mhhh.\n");
  set_strength(5);
}
