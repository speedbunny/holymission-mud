inherit "/obj/npc";

void reset(int arg) {
    ::reset(arg);
    set_name("Darth Vader");
    set_alias("darth");
    set_alt_name("vader");
    set_short("Darth Vader");
    set_level(200);
    set_al(-5000);
    
    set_long("He is dressed in all black with a black face piece.\n"+
             "He is poised for the attack and is coming at you with\n"+
             "two lightsabers aiming to take your head off.\n");
    load_chat(20, ({
      "Darth Vader says: You cannot overcome the dark side.\n",
      "Darth Vader breaths heavily.\n",
      "Darth Vader says: This one is weak.\n",
      "Darth Vader says: You must be one with the dark side.\n",
    }) );
   set_aggressive(0);
    set_chance(55);
    set_whimpy(-1);
    set_wc(110);
    set_hp(100000);
    set_spell_mess1("Darth Vader fries his opponent.");
    set_spell_mess2("Darth Vader fries you with a lightning bolt");
    set_spell_dam(400);
    set_dodge(30);
    set_fol_change(65);
    set_rid_change(15);
    set_attacks(4);
    set_attacks_change(45);
    add_money(5000);
    set_prevent_poison(1);
    set_heart_beat(1);
    set_number_of_arms(2);
}
 monster_died(ob){
   shout(this_player()->query_name()+" has defeated Darth Vader.\n");
      return 0;
} 

