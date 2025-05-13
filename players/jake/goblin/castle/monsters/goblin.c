inherit "/obj/monster";

object sword;
reset(arg) {
  ::reset(arg);
sword=clone_object("players/jake/goblin/castle/weapons/sword");
move_object(sword,this_object());
  if (arg) return 1;
  set_name("goblin");
  set_alias("goblin");
  set_alt_name("guard");
  set_short("goblin guard");
  set_long("This is a goblin guard.  He protects the castle from intruders.\n");
  set_race("goblin");
  set_level(20);
  set_al(100);
  set_hp(500);
  set_aggressive(1);
  add_money(500);
  init_command("wield sword");
  return 1;
}
