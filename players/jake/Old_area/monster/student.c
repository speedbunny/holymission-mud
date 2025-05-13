inherit "/obj/monster";

object o1,o2;
reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("student");
  set_short("Student");
  set_long("This is a college nerd.  Notice the horn-rim glasses.\nKill this geek before I puke!\n");
  set_level(5);
  set_al(1000);
  set_aggressive(0);
  set_whimpy();
o1=clone_object("players/jake/armour/glasses");
o2=clone_object("players/jake/armour/pocket");
move_object(o1,this_object());
move_object(o2,this_object());
init_command("wear glasses");
init_command("wear pocket protector");
  return 1;
}

query_moncreator() { return "jake"; }

query_monmaker() { return 1; }
