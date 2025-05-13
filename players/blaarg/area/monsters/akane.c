inherit "obj/monster";
#include "/players/blaarg/defs.h"

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("Akane");
    set_alias("akane");
    set_short("Akane");
    set_long("Akane, the beautiful daughter of Tendo, is also one of the\n"+
	     "only two people who can defeat her father in Karate. The other,\n"+
	     "Ranma, is the only man who ever defeated Akane, and now she\n"+
	     "finds herself betrothed to him because of that fact.\n"); 
    set_level(27);
    set_al(1000);
    set_hp(1250);
    set_gender(2);
    set_race("anime");
    add_money(2500);
    set_wc(19);
    set_ac(11);

}

