  

inherit "/obj/monster";
object silverclaw;

reset(arg) {
    ::reset(arg);
    if(arg) return;

    set_name("abomination");
    set_race("werewolf");
    set_short("Abomination");
    set_long("Before you stands a creature known only as Abomination.\n"
      +"Now you can see why...He is monstrous in size and exudes power.\n"
      +"From his musclature it becomes obvious that he is incredibly \n"
      +"strong and capable of performing the most brutal acts with his \n"
      +"bare hands. The look in his eyes gives the impression that he \n"
      +"is truly without a soul and not only that, but that he doesn't\n"
      +"miss it. He is a fitting definition for the words Hell-Spawned.\n");
    set_level(60);
    set_ac(40);
    set_n_wc(40);
    set_hp(30000);
    set_al(-5000);
    set_aggressive(1);
    add_money(5000+random(10000));
    set_spell_mess1("The Werewolf rakes you with his sharp claws\n");
    set_spell_mess2("You feel your ribs crack as the Wolf lands a mighty\n"+ 
                    "blow\n");
    set_chance(50);
    set_spell_dam(100);
    silverclaw=clone_object("players/kaneda/weapons/silverclaw");
    transfer(silverclaw,this_object());
    command("wield silverclaw",this_object());
    set_dead_ob(this_object());
}

monster_died(ob) {
   
    tell_room(environment(this_object()),
      "In your minds eye you can see the old man smiling at you.\n");
   
}

init() {
    ::init();
    add_action("hold","hold");
    add_action("death","death");
}
hold() {
    tell_room(environment(this_object()),
      "The Werewolf laughs saying: I have not lasted this long without\n"+
      "                            learning a few tricks of my own....\n");
    return 1;
}
death() {
    tell_room(environment(this_object()),
      "The Werewolf laughs saying: I have not lasted this long without\n"+
      "                            learning a few tricks of my own....\n");
    return 1;
}
 
