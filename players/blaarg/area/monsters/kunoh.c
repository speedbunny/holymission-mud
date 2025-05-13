inherit "obj/monster";
#include "/players/blaarg/defs.h"
object sword;

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("Kunoh");
    set_alias("kunoh");
    set_short("Kunoh Tatewaki");
    set_long("Ranma's bitter enemy, Kunoh tries everything in his power\n" +
	     "to steal Akane and <<the Pigtailed Girl>> from him.\n");
    set_level(15);
    set_al(-1000);
    set_hp(450);
    set_gender(1);
    set_race("anime");
    add_money(250);
    set_wc(15);
    set_ac(8);
    set_number_of_arms(2);
    sword=clone_object(WEAPON+"wsword");
    move_object(sword, this_object());
    command("wield sword");
}

