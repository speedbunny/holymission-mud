inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("troll");
  set_alias("troll");
  set_alt_name("**");
  set_short("A friendly troll");
  set_long("A friendly troll.\n"+
           "He is dressed in a pink suit which looks really weird.\n");
   set_gender(1);
  set_race("troll");
  set_level(10);
  set_al(150);
  add_money(250);
  set_hp(250);
  set_ep(200);
  set_aggressive(0);
  load_chat(15,({"The troll says: Hello there, how are you feeling today ?\n",
                 "The troll sniffs a flower.\n",
                 "The troll kisses you. \n",
                 "The troll hugs you.\n",}));
 load_a_chat(15,({"The troll says: Why do you want to kill me ??\n",
                  "The troll says: I don't want to fight.\n",
                  "The troll says: Let's make peace; not war.\n",}));
  set_whimpy();
  return 1;
}

query_moncreator() { return "dice"; }

query_monmaker() { return 1; }
