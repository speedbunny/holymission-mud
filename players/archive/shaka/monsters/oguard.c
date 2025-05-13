inherit "/obj/monster";

reset(arg) {
  ::reset(arg);

  if (!arg) {
    set_name("orc guard");
    set_alias("orc");
    set_alt_name("guard");
    set_short("Orc guard");
    set_long("This is a foul orc of the dark he's guarding the entrance \n"+
             "to this dark domain.\n");
    set_race("orc");
    set_gender(1);
    load_a_chat(10,({"Orc guard says: Now you must die!\n",
                     "Orc guard shouts: INTRUDERS!!\n",
                     "Orc guard blows his horn to sound alarm.\n",}));
    set_gender(1);
    set_level(5);
    set_hp(200);
    set_ep(250);
    set_al(-500);
    set_wc(1);
    set_ac(1);
    set_aggressive(1);
    set_whimpy(-1);
    add_money(50 +random(50));
    transfer(clone_object("/players/shaka/weapons/odagger")
    ,this_object());
    transfer(clone_object("/players/shaka/armour/ohelmet")
    ,this_object());
    transfer(clone_object("/players/shaka/obj/horn")
    ,this_object());
    init_command("wield dagger");
    init_command("wear helmet");
  }
}
catch_tell(str) {
   string who;
   if (sscanf(str, "%s arrives.", who) == 1)
    { say("Orc guard blows his horn as " + who + " enters his realm.\n");
      return 1;
    }
}
