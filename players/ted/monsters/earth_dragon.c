inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("earth dragon");
 set_short("A Massive Earth Dragon");
 set_race("dragon");
 set_level(17);
 set_hp(412);
 set_wc(30);
 set_ac(8);
 set_al(-900);
 set_aggressive(1);
 set_chance(50);
 set_spell_dam(42);
 set_spell_mess2("The Earth dragon burns you with molten lava!");
 set_spell_mess1("The Earth dragon spits molten lava");
}
