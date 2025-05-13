inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("medium demon");
  set_alias("demon");
  set_short("Medium Demon");
  set_long("This demon is here to guard the stairway going up\n");
  set_race("demon");
   set_level(45);
  set_al(-100);
  add_money(5000);
  set_hp(3000);
  set_wc(20);
  set_ac(20);
  set_aggressive(0);
  return 1;
}

query_moncreator() { return "warlord"; }

query_monmaker() { return 1; }
