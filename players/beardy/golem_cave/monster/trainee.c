inherit "obj/npc";

reset(arg)
{ ::reset(arg);
  if(arg) return 0;

  set_name("trainee");
  set_alt_name("trainee");
  set_short("trainee");
  set_race("golem");

  set_long("It's a trainee-golem, he looks quite simple.\n");
  set_gender(0);
  set_level(4);
  set_al(0);

  set_spell_mess1("");
  set_spell_mess2("The trainee does a combat move");
  set_spell_dam(10);
  set_chance(20);
}
