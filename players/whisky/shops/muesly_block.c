inherit "obj/food";

reset(arg) {

  if (!arg) {
    set_name("block");
    set_alias("muesly block");
    set_short("A muesly block");
  set_long("It's made of porridge, raisines, sugar and cornflakes.\n");
    set_eater_mess("ARGGGG, you now feel like to kill somebody.\n");
    set_eating_mess(" eats a mueslyblock.\n");
    set_strength(50);
    set_value(500);
    set_weight(1);
  }
}
