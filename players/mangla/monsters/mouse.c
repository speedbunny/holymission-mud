inherit "obj/monster";

#include "/players/mangla/defs.h"

reset(arg) {

    ::reset(arg);
    if (!arg) {
        set_ep(100000);
        set_name("Small Mouse");
        set_alias("mouse");
        set_race("mammal");
        set_size(1);
        set_level(15);
        set_short("Mouse");
        set_long("A harmless looking mouse, but appearances can be decieving.\n");
        set_wc(5);
        set_ac(5);
        set_al(0);
        set_int(3);
        set_con(3);
        set_chr(3);
        set_str(3);
        set_wis(3);
        set_dex(20);
        set_aggressive(0);
        add_money(0);
        set_chance(10);
        set_spell_dam(5);
        set_spell_mess2("The mouse slips into your clothes and scratches you before running out.");
        set_spell_mess1("The mouse scratches his opponent.");
    }
}

