inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("fire giant king");
 set_alias("king");
 set_short("The Fire Giant King");
 set_race("giant");
 set_long(
  "This is the King of the Fire Giants. (and he looks it) This must be\n"+
  "the largest, strongest giant you have ever seen!\n");
 set_level(19);
 set_ac(16);
 set_hp(1550);
 set_wc(40);
 set_al(-850);
 set_aggressive(1);
 set_chance(50);
 set_spell_dam(60);
 set_spell_mess1("The King calls down a rain of fire");
 set_spell_mess2("The King calls down a rain of fire on your head!");
}
