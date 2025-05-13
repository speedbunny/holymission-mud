inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("gambler");
  set_short("The incredible gambling-monster");
  set_long("The gambling-monster, always in for a game.\n");
  set_level(20);
  set_al(0);
  set_hp(1500);
  set_ep(5000);
  set_wc(10);
  set_ac(3);
  set_chance(35);
  set_spell_dam(40);
  set_spell_mess1("The monster pulls out a card, using it to chop your ear.");
  set_spell_mess2("The monster throws millions of dice, making you stumble");
  set_aggressive(1);
 move_object(clone_object(".players/dice/items/cards"),this_object());
  return 1;
}

query_moncreator() { return "dice"; }

query_monmaker() { return 1; }
