inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("rabbit");
  set_alias("rabbit");
  set_alt_name("**");
set_short("A rabbit");
set_long("A nice little rabbit living in peace here.\n");
  set_race("rabbit");
  set_level(5);
  set_al(10);
  set_hp(50);
  set_ep(50);
  set_aggressive(0);
  load_a_chat(15,({"The rabbit tried to bite you.\n",
                 "The rabbit slammed you with it's paw.\n",}));
  set_whimpy();
  return 1;
}


