inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("Neat Freak");
  set_alias("freak");
  set_short("Neat Freak");
  set_long("This monster is a very tidy monster but hates people. Don't screw with him.\nHe will hurt you bad!!\n");
  set_level(20);
  set_wc(50);
  set_ac(15);
  set_spell_mess1("");
  set_spell_mess2("");
  set_chance(2);
  set_spell_dam(120);
  set_al(-1000);
  add_money(1000);
  set_aggressive(1);
  return 1;
}


