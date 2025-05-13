inherit "obj/food";

void reset(int arg) {

  ::reset(arg);
  if(arg) return;
  set_name("smurfberry");
  set_alias("berry");
  set_short("A smurfberry");
  set_long("A small, red smurfberry.\n");
  set_value(5);
  set_weight(1);
  set_strength(2);
  set_heal_amount(2);
  set_eater_mess("Mmmm, sweet, juicy smurfberry!\n");
  set_eating_mess(" snarfs down a juicy smurfberry.\n");
}

