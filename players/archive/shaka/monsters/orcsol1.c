inherit "obj/monster";

reset(arg) {
  ::reset(arg);

  if (!arg) {
    set_name("orc soldier");
    set_alias("orc");
    set_alt_name("soldier");
    set_short("Orc soldier");
    set_long("This an soldier in the dark army of the orcs.\n");
    set_race("orc");
    set_gender(1);
    load_a_chat(10,({"Orc soldier swings his sword.\n",
                     "Orc soldier laughs at you.\n",
                     "Orc soldier says: Get away!!\n",}));
    set_level(5);
    set_hp(250);
    set_ep(250);
    set_al(-500);
    set_wc(2);
    set_ac(1);
    set_aggressive(1);
    set_whimpy(-1);
    add_money(50 + random(50));
    transfer(clone_object("/players/shaka/weapons/osword")
    ,this_object());
    init_command("wield sword");
  }
}
