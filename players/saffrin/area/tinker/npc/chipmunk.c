inherit "obj/monster";
#include "/players/saffrin/defs.h"

object crocus;

reset(){

  ::reset();
    set_name("a chipmunk");
    set_race("chipmunk");
    set_short("A chipmunk");
    set_size(1);
    set_ac(3);
    set_wc(3);
    set_alias("munk");
    set_long("A tiny little chipmunk scurrying around in search\n"+
                   "of a nut or two.\n");
    set_level(1);
    set_hp(60);

    load_chat(4,({
        "A tiny chipmunk nibbles on a nut.\n",
    }));

    MOVE(CLONE(TINK+"obj/tcrocus"),TO);
}
