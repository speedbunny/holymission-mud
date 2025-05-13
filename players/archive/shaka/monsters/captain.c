inherit "/obj/monster";

reset(arg) {
  ::reset(arg);

  if (!arg) {
    set_name("orc captain");
    set_alias("orc");
    set_alt_name("captain");
    set_short("An Orc captain");
    set_long("This is an orc captain in the legion of the orc, he's \n"+
             "commanding other orcs.\n");
    set_race("orc");
    set_gender(1);
    set_smell("The captain smell terrible.");
    load_a_chat(10,({"Orc captain laughs.\n",
                     "Orc captain shouts: Kill all intruders!\n"+
                     "Orc captain kicks you!\n",}));
    set_level(20);
    set_hp(1000);
    set_ep(2000);
    set_al(-500);
    set_wc(10);
    set_ac(3);
    set_aggressive(1);
    set_whimpy(-1);
    add_money(100 + random(100));
    set_spell_mess1("Orc captain smacked you on the head");
    set_spell_mess2("Orc smashed you with his bare hands");
    set_chance(15);
    set_spell_dam(25);
    transfer(clone_object("/players/shaka/weapons/oblade")
    ,this_object());
    transfer(clone_object("/players/shaka/armour/oshield")
    ,this_object());
    init_command("wield blade");
    init_command("wear shield");
  }
}
