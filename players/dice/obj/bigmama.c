inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("big mama");
  set_alias("mama");
  set_short("Big Mama");
  set_long("A sweet old lady, baking bread for the Coalminers.\nAs she reminds you of your mother, she might be hard to get down !\n");
  set_gender(2);
   set_level(16);
   set_race ("woman");
  set_al(0);
  set_hp(400);
  set_ep(400);
  set_wc(6);
  set_ac(2);
  set_aggressive(0);
   load_chat(5,({"Big mama says : i lost my bread. \n",
                 "Big mama searches around the counter. \n",
                 "Big mama says : Can you help me look ?.\n",}));
  add_money(300);
  return 1;
}

query_moncreator() { return "dice"; }

query_monmaker() { return 1; }
