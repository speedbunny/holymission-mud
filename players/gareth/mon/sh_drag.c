#include "/players/gareth/define.h"
inherit "/obj/npc";

reset(arg) {
    ::reset(arg);
    if(!arg) {
    set_name("Shadow Dragon");
    set_alias("dragon");
    set_short("A Shadow Dragon");
    set_long("The dragon appear as a worm like dragon of lighter.\n"+
      "and darker shadows. Its bat like wings are semi-transparent, \n" +
      "as is most of its body.  It's eyes resemble pools of feral grey \n"+
      "opalesence. It looks like it can not be subdued.\n") ;
    set_level(55);        
    set_ac(40);
set_wc(450000000);
    set_hp(5000);
    set_al(-500);
    set_aggressive(0);
    set_chance(45);
    set_spell_mess1("The dragon breathes gas of posion upon you!");
    set_spell_mess2("The dragon crushes you with its mass!");
    set_spell_dam(70);
    set_fol_change(10);
    set_attacks(2);
    set_attacks_change(25);
    
    
}

}
