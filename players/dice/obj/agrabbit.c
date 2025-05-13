inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("rabbit");
  set_alias("rabbit");
  set_alt_name("**");
  set_short("An aggressive rabbit");
  set_long("An agressive rabbit, which lives in the twilight zone.\n"+
           "It searches it way around here.\n");
  set_race("rabbit");
  set_level(10);
  set_al(-20);
  set_hp(250);
  set_ep(200);
  set_aggressive(1);
  load_chat(15,({"The rabbit tried to bite you.\n",
                 "The rabbit slammed you with it's paw.\n",}));
  set_whimpy();
  return 1;
}

query_moncreator() { return "dice"; }

query_monmaker() { return 1; }
