inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("black Demon Lady In Waiting");
    set_alt_name("lady");
    set_alias("lady in waiting");
    set_race("demon");
    set_gender(2);
    set_short("An ugly demon");
    set_long("An ugly demon.\n" +
             "This lady in waiting helps the Queen!\n" +
             "She has a tattoo of a white crown on her forehead.\n");
    set_aggressive(0);
    set_level(20);
    set_wc(31);
    set_ac(12);
    set_al(-750);
    set_hp(1585);
    move_object(clone_object(ARMR + "demons/drobe"),this_object());
    command("wear robe");
    set_chance(35);
    set_spell_dam(50);
    set_spell_mess2("The lady slaps you in the face!\n");
    set_spell_mess1("The lady slaps her opponent in the face!\n");
}
    id(str) {
        return str=="demon lady"||str=="demon"||str=="topazdemon"||str=="black demon captain"||str=="captain"||str=="black demon"; }
