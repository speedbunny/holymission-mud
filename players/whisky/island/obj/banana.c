inherit "obj/food";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("banana");
  set_short("a big ripe banana");
  set_long("It looks very tasty.\n");
  set_value(2);
  set_weight(1);
  set_eater_mess("You feel the sweet taste of the banana on your tongue. " +
                "ahh that tastes great !.\n");
  set_strength(3);
  set_heal_amount(8);
  set_eating_mess(" sexily eats a banana.\n");
}
