inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
set_name("spider");
add_money(100);
set_alias("spider");
  set_short("Big spider");
  set_long("This is probably the spider that made all of these webs.\nHe looks hungry.\n");
  set_level(10);
  set_al(-1000);
  set_ac(3);
  set_aggressive(0);
  return 1;
}

query_moncreator() { return "jake"; }

query_monmaker() { return 1; }
