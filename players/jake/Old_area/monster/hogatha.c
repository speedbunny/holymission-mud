inherit "/obj/monster";

object ruler;
reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("hogatha");
  set_alias("monitor");
  set_short("hogatha");
  set_long("This is hogatha.  The fat, mean, and ugly hall monitor.\nShe hates slackers!\n");
  set_level(15);
  set_al(500);
  set_aggressive(1);
ruler=clone_object("players/jake/weapons/ruler");
move_object(ruler,this_object());
init_command("wield ruler");
  return 1;
}

query_moncreator() { return "jake"; }

query_monmaker() { return 1; }
