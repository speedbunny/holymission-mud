inherit "/obj/monster";

object o1;
reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("firespirit");
  set_alias("spirit");
  set_alt_name("fire");
  set_short("Fire spirit");
  set_long("This is a spirit made entirely of fire.\nHe is probably the cause of the condition of this room.\n");
  set_level(20);
  set_al(-200);
set_hp(900);
  set_wc(25);
  set_ac(12);
set_chance(40);
set_spell_dam(30);
set_spell_mess1("The fire spirit throws a huge ball of flames at his opponent.\n");
add_money(1000);
set_spell_mess2("Your hair singes as he throws a ball of flames at you.\n");
  set_aggressive(0);
o1=clone_object("players/jake/stuff/key1");

move_object(o1,this_object());
  return 1;
}

query_moncreator() { return "jake"; }

query_monmaker() { return 1; }
