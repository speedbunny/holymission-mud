inherit "/obj/monster";

object armour_,blade;
reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("dust");
  set_alias("dust");
  set_alt_name("monster");
  set_short("Dust Monster");
set_long("This is a monster made of dust.\nHe isn't very friendly.\n");
  set_race("monster");
  set_level(15);
  set_al(-199);
  set_aggressive(0);
blade=clone_object("players/jake/weapons/dustblade");
armour_=clone_object("players/jake/armour/dustarmour");
move_object(blade,this_object());
move_object(armour_,this_object());
init_command("wield dust blade");
init_command("wear dust armour");
  return 1;
}

query_moncreator() { return "jake"; }

query_monmaker() { return 1; }
