inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("manx");
  set_alias("cat");
  set_level(16);
  set_short("A manx");
  set_wc(17);
  set_ac(6);
  set_al(-400);
  set_hp(750);
  set_long("An evil manx, guarding the passageway.\n");
  set_aggressive(1);
  set_chance(25);
  set_spell_mess1("The manx casts a deadly spell.");
  set_spell_mess2("The manx wounds you with a deadly spell.");
  set_spell_dam(15);
  move_object(clone_object("/players/emerald/good/obj/usword"),this_object());
}

