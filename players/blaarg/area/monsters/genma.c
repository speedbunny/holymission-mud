inherit "obj/monster";
#include "/players/blaarg/defs.h"

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("Genma");
    set_alias("genma");
    set_short("Genma");
    set_long("Genma is the father of Ranma. He is a rather colorful character,\n"+
	     "who, like Ranma, has a unique shape-changing problem. Genma\n"+
	     "changes from a human to a panda with hot and cold water.\n");
    set_level(23);
    set_al(1000);
    set_hp(750);
    set_gender(1);
    set_race("anime");
    add_money(2500);
    set_wc(15);
    set_ac(8);

}

