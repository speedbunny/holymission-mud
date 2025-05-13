inherit "/obj/monster";

reset(arg) {
  ::reset(arg);

  if (!arg) {
    set_name("hobbit guard");
    set_alias("guard");
    set_alt_name("halfling");
    set_short("A hobbit guard");
    set_long("This guard has been appointed by the village mayor in \n"+
             "order to keep unwanted visitors out.\n");
    set_race("hobbit");
    set_gender(1);
    set_size(2);
    load_chat(5,({"Guard says: Bigfolk, please watch your head.\n",
                  "Guard says: No evil orcs allowed in the village.\n",
                  "Guard says: There's lot of evil around nowadays.\n",}));
    set_gender(1);
    set_level(10);
    set_hp(700);
    set_ep(1000);
    set_al(50);
    set_wc(10);
    set_ac(4);
    set_aggressive(0);
    set_whimpy(-1);
    add_money(50 +random(100));
    transfer(clone_object("/players/shaka/weapons/hdagger")
    ,this_object());
    init_command("wield dagger");
  }
}
