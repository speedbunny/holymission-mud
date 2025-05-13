inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("steel dragon");
 set_alias("steel dragon");
 set_race("dragon");
 set_short("A Massive Steel Dragon");
 set_level(19);
 set_ep(500000);
 set_hp(412);
 set_wc(30);
 set_ac(6);
 set_al(-800);
 set_aggressive(1);
 set_chance(50);
 set_spell_dam(42);
set_spell_mess2("The Steel Dragon shreds you with a blast of metal splinters");
set_spell_mess1("The Steel Dragon spits steel splinters");
}
