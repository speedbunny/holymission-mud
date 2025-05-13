inherit "/obj/thing";

#include "/players/mangla/defs.h"

#define LOCKET "/players/exos/objects/locket"

int _locket() {
    transfer(clone_object(LOCKET),TP);
    destruct(TO);
    return 1;
}

void reset(int arg) {

    if(arg) return;
    ::reset();
    set_alias("temp");
    set_weight(0);
}

void init() {

    ::init();
    add_action("_locket","locket");
}

