inherit "/obj/monster";

object o1;
reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("smoke");
  set_short("Smoke");
  set_long("This is a hazy monster.\nIt is translucent, with glaring red eyes.\n");
  set_race("monster");
  set_level(16);
  set_al(-233);
  set_wc(16);
  set_ac(5);
add_money(700);
  set_aggressive(0);
o1=clone_object("players/jake/weapons/smblade");
move_object(o1,this_object());
init_command("wield smoke blade");
  return 1;
}

query_moncreator() { return "jake"; }

query_monmaker() { return 1; }
