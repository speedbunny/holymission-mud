inherit "obj/npc";

reset(arg)
{ ::reset(arg);
  if(arg) return 0;

  set_name("trainer");
  set_alt_name("trainer");
  set_race("golem");

  set_long("It's a golem's trainer, he looks much harder than a trainee.\n");
  set_gender(0);
  set_level(17);
  set_al(100);

  set_spell_mess1("");
  set_spell_mess2("The trainer does a combat move");
  set_spell_dam(70);
  set_chance(20);
}
