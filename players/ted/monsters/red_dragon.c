inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("red dragon");
 set_alias("flame");
 set_short("A Flame Red Dragon");
 set_race("dragon");
 set_level(15);
 set_hp(350);
 set_wc(22);
 set_al(-500);
 set_aggressive(1);
 set_chance(40);
 set_spell_dam(45);
 set_spell_mess2("The dragon blasts you with fire.");
 set_spell_mess1("The dragon breaths fire");
}
