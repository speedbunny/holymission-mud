inherit "obj/monster";
#include "/players/blaarg/defs.h"

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("Tendo");
    set_alias("tendo");
    set_short("Tendo");
    set_long("Tendo is the master of the dojo, and Akane's father. He is \n"+
	     "responsible for the training of the sensais. The only people\n"+
	     "who are possibly more powerful than him are Akane and Ranma.\n");
    set_level(25);
    set_al(1000);
    set_hp(1000);
    set_dex(30);
    set_gender(1);
    set_race("anime");
    add_money(2500);
    set_wc(18);
    set_ac(10);
    set_number_of_arms(4);

}

