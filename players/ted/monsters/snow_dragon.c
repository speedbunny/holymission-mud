inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("snow dragon");
 set_alias("white dragon");
 set_race("dragon");
 set_short("A Huge Snow Dragon");
 set_long("This huge beast has massive silver claws and huge white fangs!\n");
 set_level(19);
 set_ep(350000);
 set_hp(350);
 set_wc(22);
 set_al(-500);
 set_aggressive(1);
 set_chance(40);
 set_spell_dam(45);
 set_spell_mess2("The dragon blasts you with splinters of ice.");
 set_spell_mess1("The dragon breaths cold");
}
