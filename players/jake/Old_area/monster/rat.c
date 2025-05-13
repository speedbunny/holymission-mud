inherit "/obj/monster";
object claw;
reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("rat");
  set_short("rat");
  set_long("A small brown rat.\nHe has sharp-looking yellow teeth, and a long pink tail.\n");
  set_level(5);
  set_al(-1000);
  add_money(50);
  set_ac(3);
  set_aggressive(1);
claw=clone_object("players/jake/weapons/rclaw");
move_object (claw,this_object());
init_command ("wield claw");
  return 1;
}

query_moncreator() { return "jake"; }

query_monmaker() { return 1; }
