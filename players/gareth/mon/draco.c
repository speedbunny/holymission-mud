inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(!arg) {
    set_name("huge dracolisk");
    set_alias("dracolisk");
    set_race("dragon");
    set_short("A Dracolisk");
    set_long("You see the offspring of a black dragon and basilisk.\n"+
      "Its scales are of a deep brown color. It moves with relative \n" +
      "due to its six legs, each tiped with razor sharp talons. Its \n"+
      "teeth are the size of swords. It drools as it stares at you.\n") ;
    set_level(55);        
    set_ac(35);
set_wc (4500000000);
    set_hp(4500);
    set_al(-1500);
    set_aggressive(0);
    set_chance(65);
    set_spell_mess1("The dracolisk spits acid on you");
    set_spell_mess2("The dracolisk claws at you with its talons!");
    set_spell_dam(75);
    

}

}
