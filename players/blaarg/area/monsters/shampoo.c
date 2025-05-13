inherit "obj/monster";
#include "/players/blaarg/defs.h"
reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("Shampoo");
    set_alias("shampoo");
    set_short("Shampoo");
    set_long("Shampoo, the beautiful proprietor of this restaurant, is\n"+
	     "also quite powerful. She is the only female to defeat Akane\n"+
	     "in Karate, and has also been defeated by Ranma, so she is\n"+
	     "bound to him even though she can never marry him. She, like\n"+
	     "Ranma, changes form with water. Her form changes are from\n"+
	     "human to cat.\n");
    set_level(25);
    set_al(1000);
    set_hp(950);
    set_gender(2);
    set_race("anime");
    add_money(2500);
    set_wc(18);
    set_ac(10);
}



