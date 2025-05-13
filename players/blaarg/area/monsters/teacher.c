inherit "obj/monster";
#include "/players/blaarg/defs.h"
reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("Teacher");
    set_alias("teacher");
    set_short("A Teacher");
    set_long("A teacher...she is involved in her work.\n");
    set_level(20);
    set_al(1000);
    set_hp(550);
    set_gender(2);
    set_race("anime");
    add_money(1000);
    set_wc(15);
    set_ac(11);
    set_number_of_arms(2);
}

