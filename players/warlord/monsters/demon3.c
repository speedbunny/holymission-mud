inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("great demon");
  set_alias("demon");
  set_short("Great Demon");
  set_long("This demon is here to see that no one will pass..\n");
  set_race("demon");
  set_level(60);
  set_al(-100);
  set_hp(8000);
  set_wc(20);
  set_ac(20);
  set_aggressive(1);
  return 1;
}


