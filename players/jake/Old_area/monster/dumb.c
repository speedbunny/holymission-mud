inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("dumb");
  set_alt_name("student");
set_short("Dumb student");
  set_long("Sure! he is happy to see you!\nHe's too dumb to not like anyone!\n(had ya going there for a second)\n");
set_level(10);
  set_al(1000);
set_wc(5);
set_ac(3);
add_money(150);
  set_aggressive(0);
  set_whimpy();
  return 1;
}

query_moncreator() { return "jake"; }

query_monmaker() { return 1; }
