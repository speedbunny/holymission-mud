inherit "obj/monster";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg){
    ::reset();
    set_name("eunuch");
    set_race("human");
    set_gender(0);
    set_alias("slave");
    set_short("The Count's Eunuch");
            set_long(
"This poor man looks as if he is missing something.  He is dressed in "+
"black leather shorts and has chains draped across his chest.  A velvet "+
"mask covers his face and a dog chain is connected to a color on his neck.\n");
    set_level(1);
    set_hp(50);
    set_al(0);
    set_ac(0);
    set_wc(5);
    }
