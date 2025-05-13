inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("Killer bee");
  set_alias("bee");
  set_alt_name("killer bee");
  set_short("A killer bee");
   set_long("A bee flying around, searching for flowers.\n");
  set_race("animal");
  set_level(12);
  set_al(0);
  set_hp(50);
  set_ep(50);
  set_wc(7);
  set_ac(0);
  set_aggressive(1);
     load_chat(10,({"The killer bee buzzes around your head.\n",
                     "BBBBBUUUUZZZZZZZ\n",
                     "HUMMMMMMM\n",
                      "The bee flies up your leg.\n",
                      "The killer bee tries to sting you!\n",}));
  set_whimpy();
  return 1;
}

query_moncreator() { return "dice"; }

query_monmaker() { return 1; }
