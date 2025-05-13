inherit "/obj/npc";

reset(arg) {
    ::reset(arg);
    if(!arg) {
    set_name("Darth Vader");
    set_alt_name("vader");
    set_short("Darth");
    set_alias("darth","vader");
    set_long("He is dressed in all black with a black face piece.\n"+
             "He is poised for the attack and is coming at you with\n"+
             "two lightsabers aiming to take your head off.\n");
    load_chat(20, ({
      "Darth Vader says: You cannot overcome the dark side.\n", 
      "Darth Vader breaths heavily.\n", 
      "Darth Vader says: This one is weak.\n", 
      "Darth Vader says: You must be one with the dark side.\n", 
    }) ); 
    set_prevent_poison(1);
    set_heart_beat(1);
    set_number_of_arms(2);
    move_object(clone_object("players/sargon/cloak.c"), this_object());
    move_object(clone_object("players/mangla/guild/lightsaber.c"), this_object());
    move_object(clone_object("players/mangla/guild/lightsaber.c"), this_object());
    command("wear cloak");
    command("wield handle");
    command("wield handle 2");
    set_level(200);
    set_ac(55);
    set_wc(110);
    set_hp(100000);
    set_al(-1000);
    set_aggressive(0);
    set_chance(55);
    set_spell_mess1("Darth Vader fries his opponent.");
    set_spell_mess2("Darth Vader fries you with a lightning bolt");
    set_spell_dam(400);
    set_dodge(30);
    set_fol_change(65);
    set_rid_change(15);
    set_attacks(4);
    set_attacks_change(45);
    add_money(5000);

    


}

}
