#include "/players/gareth/define.h"
inherit "obj/npc";

reset(arg) {
    ::reset(arg);
    if(!arg) {
    set_name("Golden Gorger");
    set_alias("gorger");
    set_short("A Gorger");
    set_long("A badger like creature with a golden coat, that\n"+ 
             "shines as bright as real gold. You notice it has\n"+ 
             "eight legs, each tipped with copper colored claws.\n"+ 
             "As it growls you notice that its teeth seem to be\n"+ 
             "made of cooper as well. Its eyes are silvery with\n"+
             "golden pupils.\n") ;
    set_level(50);        
    set_ac(60);
set_wc(6000000);
    set_hp(5500);
    set_al(-500);
    set_aggressive(1);
    set_chance(45);
    set_spell_mess1("The Gorger's powerful jaws dig into your flesh!");
    set_spell_mess2("You are torn apart by the Gorger's claws!");
    set_spell_dam(75);
    set_attacks(2);
    set_attacks_change(65);
    set_dodge(55);
    set_fol_change(15);

}

}
