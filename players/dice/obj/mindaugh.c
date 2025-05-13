inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("miners daughter");
  set_alias("daughter");
  set_alt_name("girl");
  set_short("Miners daughter");
  set_long("The miners daughter, just came out of school, where she's learning \nto be a teacher.\n");
  set_level(2);
  set_al(0);
  set_hp(175);
  set_ep(170);
  set_gender(2);
  set_wc(2);
  set_ac(1);
  load_chat(10,({"The girl says : Do you like my room ?? \n",
                 "The girl says : My father did this himself.\n",
                 "The girl says : Only my brothers room needs to be done.\n",
                 "The girl grins happily \n",}));
  set_aggressive(0);
  return 1;
}

query_moncreator() { return "dice"; }

query_monmaker() { return 1; }
