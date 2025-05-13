inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("relaxing Demon Guard");
    set_alt_name("guard");
    set_alias("topazdemon");
    set_race("demon");
    set_short("An ugly demon");
    set_long("This demon is ugly.\n" +
             "This guard doesn't like the way you look!\n" +
             "It has a tattoo of a white crown on it's chest.\n");
    set_aggressive(1);
    set_level(14);
    set_wc(19);
    set_ac(6);
    set_al(-130);
    set_hp(530);
    move_object(clone_object(ARMR + "demons/dshield"),this_object());
    move_object(clone_object(WEAP + "demons/trident"),this_object());
    command("wield trident");
    command("wear shield");
    set_chance(10);
    set_spell_dam(10);
    set_spell_mess2("The guard burns you with its trident.\n");
    set_spell_mess1("The guard burns its opponent with its trident.\n");
}
