inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("black widow");
  set_race("spider");
  set_short("Black widow");
  set_long("A hideous-looking black widow spider.\n");
  set_alias("widow");
  set_al(-500);
  set_level(15);
  set_hp(250);
  set_wc(12);
  set_ac(12);
  add_money(200);
  set_chance(20);
  set_spell_mess1("The spider hisses and rears up!");
  set_spell_mess2("The spider hisses and bites you hard!");
  set_spell_dam(30);
}
