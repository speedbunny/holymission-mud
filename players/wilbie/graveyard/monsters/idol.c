inherit "obj/monster";
#include "/players/wilbie/def.h"

reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("idol");
    set_alias("statue");
    set_number_of_arms(6);
    set_level(25);
    set_hp(7000);
    set_ep(10000);
    set_al(-100);
    set_gender(2);
    add_money(1000);
    set_race("undead");
    set_short("An idol of a six-armed goddess");
    set_long("It is a huge stone statue of a six-armed goddess, standing "+
             "over 20 feet high and wielding a black sword in each hand!!\n");
    set_wc(2);
    set_ac(10);
    set_size(5);
    set_aggressive(1);
    set_spell_mess1("The idol strikes with a resounding crash!!");
    set_spell_mess2("The idol smashes you with a resounding crash!!");
    set_chance(15);
    set_spell_dam(20+random(80));
    return;
}
