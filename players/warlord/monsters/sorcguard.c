inherit "obj/monster";
reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("guard");
  set_short("Sorceror Guard");
  set_long("This guard is here to make sure that all obey the rules of the MUD.\n");
       (" of the MUD.\n");
  set_level(10);
  set_al(100);
  set_hp(500);
set_wc(20);
  set_ac(10);
  set_aggressive(0);
  return 1;
  }
