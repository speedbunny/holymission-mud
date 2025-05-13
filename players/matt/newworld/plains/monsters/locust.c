inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("locust");
  set_alias("giant locust");
  set_race("insect");
  set_short("Giant locust");
  set_long("A disgusting, disease-ridden locust.\n");
  set_level(10);
  set_hp(100);
  set_al(-400);
  set_wc(7);
  set_ac(7);
  add_money(75);
  set_chance(5);
  set_spell_dam(25);
  set_spell_mess1("The locust spreads pestilence!");
  set_spell_mess2("You are suddenly struck with disease!");
}
