inherit "/obj/monster"; 
   reset(arg) {
    ::reset(arg);
     if(arg) return;
    
    set_name("Monument guard");
    set_alias("guard");
    set_short("A sleepy guard");
    set_long("The guard seems to be half asleep. he is slumped against "+ 
             "the monument.\n");
 
    set_gender(1);
    set_level(15);
    set_aggressive(0);
    set_al(-100);  
    set_chance(10);
    set_spell_mess1("Spins his mace and brings it down on your head.");
    set_spell_mess2("Brings his foot up and kicks you hard.");
    set_spell_dam(20);
    add_money(1000);
}
 
