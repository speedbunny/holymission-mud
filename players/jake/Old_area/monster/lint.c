inherit "/obj/monster";

object o1;
reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("lint monster");
  set_alias("monster");
set_alt_name("lint");
add_money(850);
  set_short("Lint Monster");
  set_long("The pile of lint seems to have come to life.\nThis is a monster made entirely of lint.\n");
  set_level(13);
  set_al(-1000);
  set_wc(10);
  set_ac(4);
  set_aggressive(1);
o1=clone_object("obj/bag");
move_object(o1,this_object());
  return 1;
}

query_moncreator() { return "jake"; }

query_monmaker() { return 1; }
