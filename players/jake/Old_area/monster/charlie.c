inherit "/obj/monster";

object o1;
reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("charlie");
set_short("Charlie");
set_long("This is Charlie.  He hates all people.\nHe stands over 6 feet tall, and has arms the size of tree trunks.\n");
  set_level(17);
  set_al(-999);
  set_aggressive(1);
o1=clone_object("players/jake/weapons/club");
move_object(o1,this_object());
init_command("wield club");
  return 1;
}

query_moncreator() { return "jake"; }

query_monmaker() { return 1; }
