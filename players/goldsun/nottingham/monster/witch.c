inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("evil nottingham witch");
  set_alias("witch");
  set_level(50);
  set_hp(3000);
  set_weight(25);
  set_wc(50);
  set_al(-1500);
  set_aggressive(1);
  set_short("nottingham demon");
  set_long("This is evil nottingham witch. She is very ugly.\n");
  set_gender(2);
  set_ac(7);
  set_spell_mess2("The witch casts a spell and you get blood on your face!\n");
  set_spell_mess1("The witch casts a spell.\n");
  set_spell_dam(70);
  set_chance(15);
}

