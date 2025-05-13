inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("mineguard");
  set_alias("guard");
  set_alt_name("**");
  set_short("A miners guard");
  set_long("A miners guard, guarding the valueable items that sometimes come from the \nmines, like diamonds, and gems.\nHe's wearing a black mythril suit, which gives him a frightening look.\n");
  set_race("coalminer");
  set_level(12);
  set_al(150);
  set_hp(250);
  set_ep(200);
  set_aggressive(1);
  load_chat(10,({"The guard looks mean at you.\n",
                 "The guard says : Don't touch the treasure.\n",}));
  set_whimpy();
  return 1;
}

query_moncreator() { return "dice"; }

query_monmaker() { return 1; }
