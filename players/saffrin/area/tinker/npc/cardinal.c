inherit "obj/monster";
#include "/players/saffrin/defs.h"

object rose;

reset(){

  ::reset();
    set_name("a chirping cardinal");
    set_race("cardinal");
    set_short("A chirpping cardinal");
    set_size(1);
    set_ac(3);
    set_wc(3);
    set_size(1);
    set_alias("bird");
    set_long("This sweet cardinal is chirpping a love song to its mate.\n"+
                   "It is red with a small orange beak.\n");
    set_level(1);
    set_hp(60);

    load_chat(4,({
        "CHIRP.....CHIRP.....CHIRP......\n",
    }));

   MOVE(CLONE(TINK+"obj/trose"),TO);
}
