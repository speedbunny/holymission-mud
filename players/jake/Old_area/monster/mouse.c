inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("mouse");
set_short("mouse");
  set_long("This is a small house mouse.\n");
  set_race("mouse");
  set_level(5);
  add_money(50);
  set_al(1000);
  set_aggressive(0);
  return 1;
}

query_moncreator() { return "jake"; }

query_monmaker() { return 1; }
