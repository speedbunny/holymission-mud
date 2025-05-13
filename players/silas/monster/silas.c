inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("wizard");
  set_alias("strange silas");
  set_short("Strange Silas the courter of sheep (different)");
  set_long("This wax likeness of Silas looks remarkably like the wizard himself. His clothes\nare covered with small tufts of wool and he smells like a sheep. The fierce look\nin his eyes however prevents you from laughing aloud at this strange wizard.\n");
  set_race("human");
  set_level(31);
  set_al(500);
  set_hp(8000);
  set_ep(3000000);
  set_wc(30);
  set_ac(5);
  set_chance(20);
  set_spell_dam(60);
  set_spell_mess1("Silas blasts you with his ancient oak staff.");
  set_spell_mess2("The smell of sheep enters your nasal passages and almost knocks you out.");
  set_aggressive(0);
  add_money(3500+random(1500));
  move_object(clone_object("players/silas/weapon/oakstaff"),
  this_object());
  move_object(clone_object("players/silas/armor/woolcoat"),
  this_object());
  init_command("wear coat");
  move_object(clone_object("players/silas/armor/chain"),
  this_object());
  init_command("wear chain");
  return 1;
  return 1;
}

query_moncreator() { return "silas"; }

query_monmaker() { return 1; }
