inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("little rat");
  set_alias("rat");
  set_alt_name("little rat");
  set_short("A little rat");
  set_long("A little rat scurrying around the alley.\n");
  set_race("animal");
  set_level(2);
  set_al(0);
  set_hp(60);
  set_ep(150);
  set_wc(1);
  set_ac(1);
  set_aggressive(0);
     load_chat(10,({"The little rat searches the corner. \n",
                    "The little rat squeeeeks !! \n",}));
  set_whimpy();
  return 1;
}

query_moncreator() { return "dice"; }

query_monmaker() { return 1; }
