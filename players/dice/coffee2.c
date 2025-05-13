inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("lag");
  set_alias("lag");
  set_short("lag");
 set_long("A monster that hunts only pple from R'dam.\n");
   set_level(2);
   set_race ("monster");
  set_al(-100);
  set_hp(1);
  set_ep(0);
  set_wc(3);
  set_ac(5);
  set_aggressive(0);
  load_chat(10,({"Lag tells you: You're mine.\n",
   "Lag says: I love kicking the network.\n",}));
  add_money(0);
  return 1;
}


