inherit "/obj/monster";

object o1;
reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("walkman");
  set_alias("man");
  set_alt_name("walk");
  set_short("Walkman");
  set_long("This is a walkman.  He is a creature who loves loud music.\n");
  set_race("monster");
  set_level(15);
  add_money(550);
  set_al(0);
set_hp(220);
set_wc(15);
  set_chance(15);
  set_spell_dam(10);
  set_spell_mess1("Walkman cranks the tunes REAL loud.");
  set_spell_mess2("Walkman deafens you as he cranks the tunes.");
  set_aggressive(0);
o1=clone_object("players/jake/armour/head");
move_object(o1,this_object());
init_command("wear head phones");
  return 1;
}

query_moncreator() { return "jake"; }

query_monmaker() { return 1; }
