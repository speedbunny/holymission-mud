inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("black Demon General");
    set_alt_name("general");
    set_alias("general");
    set_race("demon");
    set_short("An ugly demon");
    set_long("An ugly demon.\n" +
             "This demon general will die before he lets you go near the king!\n" +
             "It has a tattoo of a white crown on it's chest.\n");
    set_aggressive(1);
    set_level(30);
    set_wc(41);
    set_ac(22);
    set_al(-900);
    set_hp(3135);
    move_object(clone_object(ARMR + "tower/dplatemail"),this_object());
    move_object(clone_object(WEAP + "tower/flamesword"),this_object());
    command("wear platemail");
    command("wield sword");
    set_chance(50);
    set_spell_dam(50+(random(50)));
     set_spell_mess2("The general BLASTS you with HELLFIRE!!\n");
    set_spell_mess1("The general BLASTS his opponent with HELLFIRE!!\n");
}
    id(str) {
        return str=="demon general"||str=="demon"||str=="topazdemon"||str=="black demon general"||str=="general"||str=="black demon"; }
