inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("miner's wife");
  set_alias("wife");
  set_alt_name("miners wife");
  set_short("Miner's wife");
  set_long("The miners wife, waiting for her husband to come home.\nMeanwhile she is making dinner for the entire family.\n");
  set_race("woman");
  set_level(3);
  set_al(0);
  set_hp(200);
  set_ep(200);
  set_wc(3);
  load_chat(10,({"The wife says : Have you seen my husband ?? \n",
                "The wife smiles tiredly. \n",
                "The wife cooks something great. \n",}));
  set_ac(1);
  set_aggressive(0);
  return 1;
}

query_moncreator() { return "dice"; }

query_monmaker() { return 1; }
