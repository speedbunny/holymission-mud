inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("black Demon Queen");
    set_alt_name("queen");
    set_alias("demon queen");
    set_race("demon");
    set_short("An ugly demon");
    set_long("An ugly demon.\n" +
             "The demon Queen looks very powerful.\n" +
             "She has a tattoo of a white crown on her forehead.\n");
    set_aggressive(0);
    set_level(30);
    set_wc(41);
    set_ac(22);
    set_al(-900);
    set_hp(3135);
    move_object(clone_object(ARMR + "demons/qrobe"),this_object());
    move_object(clone_object(WEAP + "demons/qsceptre"),this_object());
    command("wear robe");
    command("wield sceptre");
    set_chance(50);
    set_spell_dam(50+(random(50)));
     set_spell_mess2("The Queen throws a curse at you!!\n");
    set_spell_mess1("The Queen throws a curse at her opponent!!\n");
}
    id(str) {
        return str=="demon queen"||str=="demon"||str=="topazdemon"||str=="black demon queen"||str=="queen"||str=="black demon"; }
