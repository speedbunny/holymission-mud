inherit "obj/monster";
#include "/players/bobo/monsters/defs.h"
reset(arg) {
    ::reset (arg);
    if(arg) return;
    set_name("halfling guard");
    set_alias("guard");
    set_level(14);
    set_wc(18);
    set_ac(5);
    set_al(0);
    set_gender(1);
    set_race("halfling");
    set_short("Guard");
    set_long("The guard in front of you is a well equiped halfling.  He\n"+
      "is wearing a blue tunic and is carrying a large polearm.\n"+
      "He is very well muscled and prepared for your advances.\n");
    add_money(150);
    MO(CO("/players/bobo/obj/polearm"), TO);
}
/*need to add a func that prevents attacking halflingl.c*/
