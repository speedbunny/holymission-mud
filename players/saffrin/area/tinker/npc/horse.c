inherit "obj/monster";
#include "/players/saffrin/defs.h"

object brasses;

reset(){

  ::reset();
    set_name("A horse");
    set_race("horse");
    set_short("A horse");
    set_wc(4);
    set_alias("horse");
    set_long("A brown horse with soft brown eyes.  He stands here whinnying while\n"+
                   "he waits to be fed.\n");
    set_level(2);
    set_size(4);
    set_hp(70);
    set_ac(4);

    load_chat(4,({
        "You hear a whinny from the horse.\n",
        "The horse stomps his hoof.\n",
    }));

    MOVE(CLONE(TINK+"obj/brasses"),TO);
}
