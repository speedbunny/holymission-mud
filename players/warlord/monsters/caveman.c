inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("caveman");
  set_short("Caveman");
 set_long("This is very dumb looking caveman, but he is huge.\n");
  set_level(15);
  set_al(200);
  add_money(200);
  set_hp(400);
  set_wc(18);
  set_ac(10);
  set_aggressive(0);
  return 1;
}

query_moncreator() { return "warlord"; }

query_monmaker() { return 1; }
