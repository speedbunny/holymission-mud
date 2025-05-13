inherit "/obj/monster";
object o1,o2;

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("cybertek");
  set_short("Cybertek");
  set_long("This is a well designed machine. its purpose is to see\nthis ship reaches it destination safely\n");
  set_level(15);
  set_al(300);
  set_hp(600);
  set_wc(15);
  set_ac(5);
  set_aggressive(0);
  o1=clone_object("players/warlord/laser");
  o2=clone_object("players/warlord/carmor");
  transfer(o1,this_object());
  transfer(o2,this_object());
  init_command("wield laser pistol");
  init_command("wear cyber armor");
  return 1;
}

query_moncreator() { return "warlord"; }

query_monmaker() { return 1; }
