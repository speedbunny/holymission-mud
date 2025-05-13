#include "/players/gareth/define.h"
inherit "/obj/npc";
object hatchet;

reset(arg) {
    ::reset(arg);
    if(!arg) {
    set_name("xodak");
    set_alias("xodak");
    set_short("Abyassal xodak");
    set_long("The sexless Xodak has dark gray, pearly skin.\n"+
      "The muscular body has no hair, and the head is long with\n"+ 
      "oddly distrorted features. It's eyes are milky white,\n"+ 
      "vertical ovals of large size. He is the guardian of the\n"+ 
      "dreaded underworld.\n") ;
    set_race("shadow");
    set_level(55);        
    set_ac(50);
set_wc(550000000);
    set_hp(4500);
    set_al(-1000);
    set_aggressive(0);
    set_chance(65);
    set_spell_mess1("You feel weak as you meet the Xodak's death gaze!");
    set_spell_mess2("Xodac pummels you to bits!");
    set_spell_dam(60);
    set_dodge(50);
    set_fol_change(0);
    set_attacks(2);
    set_attacks_change(45);
    add_money(8000);
    
/*
    hatchet=TR(CO(ITEM+"hatchet"),TO);        
    init_command("wield hatchet");
*/


}

}
