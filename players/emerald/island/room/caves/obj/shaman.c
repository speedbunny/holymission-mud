inherit "/obj/monster";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("orc shaman");
  set_alt_name("shaman");
  set_short("An orc shaman");
  set_race("orc");
  set_long("A wise looking orc.\n");
  set_gender(1+random(1));
  set_aggressive(1);
  set_level(14);
  load_a_chat(20, ({
           query_name()+" growls: Grrrrz shrzz\n",
           query_name()+" growls: Snrzlfrzzz jumm\n",
           query_name()+" growls: Ranzrkrkzzz\n",
  }));
  set_al(-2000);
  add_money(500+random(500));
  set_spell_mess1("The Orc shaman casts a flamestrike !\n");
  set_spell_mess2("You are hit by a flamestrike !\n");
  set_chance(50);
  set_spell_dam(50+random(40));
}

int detect_invis() {
    return 1;
}
