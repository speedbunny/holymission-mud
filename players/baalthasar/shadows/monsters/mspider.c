inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(!arg) {

  set_name("Mist Spider");
  set_alias("spider");
  set_level(12);
  set_con(15);
  set_dex(15);
  set_str(15);
  set_al(-25);
  set_long("A wispy form of spider over six feet tall can be seen against the \n"+
    "darkness. \n\n");
  set_ac(12);
  set_wc(12);
  set_hp(300);
  set_aggressive(1);
set_chance(40);
  set_spell_dam(60);
  set_spell_mess2("The Spider opens its maw and a blast of frost knocks you down! \n");
set_spell_mess1("Cold air hits you as the spider blasts its foe with an ice sheet! \n");
}
}
