inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("fire giant archer");
 set_alias("archer");
 set_short("A Fire Giant Archer");
 set_race("giant");
 set_long("This is the King's Archer. He is dressed in brilliant red attire.\n");
 set_level(15);
 set_ac(6);
 set_hp(390);
 set_wc(25);
 set_al(-550);
 set_whimpy(25);
 set_aggressive(1);
 set_chance(40);
 set_spell_dam(40);
 set_spell_mess1( "The Archer fires a flurry of arrows");
 set_spell_mess2( "The Archer pincushions you with a flurry of arrows!");
}
