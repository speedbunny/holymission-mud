inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
 set_name("Evil spirit");
  set_alias("spirit");
  set_alt_name("evil spirit");
  set_short("An evil spirit");
   set_long("An evil spirit, obeying only his demonic God.\n");
  set_race("spirit");
  set_level(20);
  set_al(-80);
  set_hp(500);
  set_ep(250);
  set_wc(14);
  set_ac(1);
  set_aggressive(1);
     load_a_chat(15,({"The spirit haunts you in your head.\n",
                      "The spirit says: Why did you disturbe our peace ??\n" 
                      }));
  set_whimpy();
  return 1;
}

query_moncreator() { return "dice"; }

query_monmaker() { return 1; }
