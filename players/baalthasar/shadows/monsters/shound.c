inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(!arg) {

  set_name("Spectral Hound");
set_alias("hound");
  set_level(16);
  set_dex(18);
  set_str(18);
  set_con(18);
  set_al(-60);
  set_long("You see a massive and dark shadow of a huge dog with yellow eyes. \n"+
"The beast seems to shimmer in and out of this world. \n");
  set_ac(14);
  set_wc(16);
  set_hp(400);
set_aggressive(1);
  set_spell_dam(25);
  set_chance(35);
  set_spell_mess2("The Spectral Hound claws deeply into your chest! \n"+
"A cold feeling overcomes you... \n");
  set_spell_mess1("The Spectral Hound's claws tear into its enemy's chest! \n");
}
  }
