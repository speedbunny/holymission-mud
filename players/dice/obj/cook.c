inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("cook");
  set_short("Cook");
  set_long("A very fat and ugly Cook, very capable at baking bread.\nHe looks very tired, for baking bread for all the coalminers is a heavy duty.\n");
  set_level(18);
  set_al(0);
  set_hp(400);
  set_ep(400);
  set_wc(7);
  set_ac(2);
  set_gender(1);
  set_aggressive(0);
   add_money(400);
  load_chat(10,({"The cook says: How can i cook without flour ??\n",
                 "The cook looks sad.\n",
                 "The cook says: I don't have any flour left. \n",}));
  return 1;
}

query_moncreator() { return "dice"; }

query_monmaker() { return 1; }
