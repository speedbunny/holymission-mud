inherit "/obj/monster";
reset (arg) {
  ::reset(arg);
  if (arg)return 1;
  set_name("sorceror");
  set_short("Great Sorceror");
  set_long("This is the Great Sorceror. He enjoys his sleep.\n");
  set_level(30);
  set_al(100);
  set_spell_dam(70);
  return 1;
  }
