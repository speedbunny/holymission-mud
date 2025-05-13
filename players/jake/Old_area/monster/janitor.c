inherit "/obj/monster";

object o1;
reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("sam");
  set_alias("janitor*");
set_short("Sam the janitor");
  set_long("This is Sam the janitor.  He is very tired. \nPlease don't bother him.\n");
  add_money(500);
  set_level(18);
  set_al(0);
  set_ac(5);
  set_aggressive(0);
o1=clone_object("players/jake/weapons/mop");
move_object(o1,this_object());
init_command("wield mop");
  return 1;
}

query_moncreator() { return "jake"; }

query_monmaker() { return 1; }
