inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("miners son");
  set_alias("son");
  set_alt_name("moners son");
  set_short("Miners Son");
  set_long("The miners son, just starting to work in the mines.\n");
  set_level(2);
  set_al(0);
  set_hp(175);
  set_ep(170);
  set_gender(1);
  set_wc(2);
  set_ac(1);
  load_chat(10,({"The boy says : I want my room to be redecorated. \n",}));
  set_aggressive(0);
  return 1;
}

query_moncreator() { return "dice"; }

query_monmaker() { return 1; }
