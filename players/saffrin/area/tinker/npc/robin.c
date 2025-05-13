inherit "obj/monster";
#include "/players/saffrin/defs.h"

object daisy;

reset(){
  ::reset();
    set_name("a red breasted robin");
    set_race("robin");
    set_short("a red breasted robin");
    set_size(1);
    set_ac(3);
    set_wc(3);
    set_size(1);
    set_alias("bird");
    set_long("This is a small red breasted robin that is flying around in\n"+
                   "search of a mate.\n");
    set_level(1);
    set_hp(60);

    load_chat(4,({
        "A red breasted robin flies by you.\n",
    }));

    MOVE(CLONE(TINK+"obj/tdaisy"),TO);
}
