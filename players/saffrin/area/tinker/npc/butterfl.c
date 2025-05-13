inherit "obj/monster";
#include "/players/saffrin/defs.h"

object safflower;

reset(){

  ::reset();
    set_name("a colorful butterfly");
    set_race("butterfly");
    set_short("A colorful butterfly");
    set_size(1);
    set_ac(3);
    set_wc(3);
    set_alias("fly");
    set_long("A beautiful multicolored butterfly with blue and green blended\n"+
                   "throughout its wings.\n");
    set_level(1);
    set_hp(60);

    load_chat(4,({
        "A colorful butterfly flits from one flower to another.\n",
    }));

    MOVE(CLONE(TINK+"obj/tsaff"),TO);
}
