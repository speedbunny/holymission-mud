inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("hell hound");
 set_alias("hound");
 set_short("A Large Hell Hound");
 set_race("hound");
 set_long("This is a large black hound. It's jaws are very large and powerfull,\n"+
  "but it's main weapon is the blast of hell fire it can breath out.\n");
 set_level(15);
 set_ac(8);
 set_hp(350);
 set_wc(25);
 set_al(-750);
 set_aggressive(1);
 set_chance(80);
 set_spell_dam(35);
 set_spell_mess2("The hell hound blasts you with hell fire");
 set_spell_mess1("The hell hound lets loose a blast of hell fire");
}
