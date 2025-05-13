 inherit "obj/monster";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("ogre magi");
  set_alias("magi");
  set_race("ogre");
  set_short("An Ogre Magi");
  set_long("This is an oriental looking ogre dressed in a sari and sash.\n");
  set_level(14);
  set_hp(290);
  set_ac(3);
  set_al(-150);
  set_chance(30);
  set_spell_dam(30);
  set_spell_mess2("The Orge Magi proforms a delicate dance of magical death against you!");
  set_spell_mess1("The Ogre Magi begins a complex sutra");
}
