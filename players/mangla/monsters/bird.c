inherit "obj/monster";

#include "/players/mangla/defs.h"

reset(arg) {

    ::reset(arg);
    if (!arg) {
        set_name("bird");
        set_alias("bird");
        set_race("bird");
        set_size(2);
        set_level(6);
        set_short("Bird");
        set_long("A rather average bird except for the very pointy beak.\n");
        set_no_fight(1);
        set_wc(8);
        set_ac(6);
        set_hp(100);
        set_al(0);
        set_dex(15);
        set_aggressive(0);
        add_money(0);
        set_chance(30);
        set_spell_dam(5);
        set_spell_mess2("The bird swoops up and dive bombs you.");
        set_spell_mess1("The bird drops a load onto its opponent.");
    }
}

