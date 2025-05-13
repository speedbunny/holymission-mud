#include "/players/blaarg/defs.h"
inherit "obj/monster";
reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("Moose");
    set_alias("moose");
    set_short("Moose");
    set_long("Moose is a friend of Ranma, and wants to marry Shampoo.\n");
    set_level(23);
    set_al(750);
    set_hp(1000);
    set_gender(1);
    set_race("anime");
    add_money(2000);
    set_wc(17);
    set_ac(10);
}

