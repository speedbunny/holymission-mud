inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("owner");
  set_alias("owner");
  set_short("Owner of the house");
   set_long("This man looks like the owner of the house.\n");
   set_level(16);
   set_gender(1);
   set_race ("man");
  set_al(0);
  set_hp(500);
  set_ep(400);
  set_wc(6);
  set_ac(2);
  set_aggressive(0);
   load_chat(20,({"The owner says: Now you're as lost as I am.\n",
                 "The owner looks sad.\n",
                 "The owner says: I fell through that wall too.\n",
                 "The owner says: There is no way out.\n",
                 "The owner says: Can you get us out ?\n",}));
  add_money(300);
  return 1;
}


query_monmaker() { return 1; }
