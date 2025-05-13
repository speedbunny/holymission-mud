inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("kid");
  set_alias("coalminer kid");
  set_short("A coalminer kid");
  set_long("A small kid, just came out of school.\nHe's wearing a rather old looking sweater, and looks happy\nthat he might get a new one next year.\n");
  set_race("coalminer");
  set_level(2);
  set_al(200);
  set_hp(100);
  set_ep(100);
  set_gender(1);
  set_ac(1);
  set_aggressive(0);
  load_chat(10,({"The kid bounces with a ball. \n",
                 "The kid smiles happily. \n",
                 "The kid says : Will you play with me ?? \n",}));
  set_whimpy();
  return 1;
}

query_moncreator() { return "dice"; }

query_monmaker() { return 1; }
