inherit "obj/armour";
#include "/players/saffrin/defs.h"

reset(arg) {
    if(arg) return;
    set_name("Medal of Valour");
    set_alias("medal");
    set_short("Denmark Medal of Valour");
    set_long("The Denmark Medal of Valour for defeating Hamlet.\n");
    set_weight(0);
    set_ac(0);
    set_value(0);
    set_type("sticker");
}
query_auto_load() {
    return HAM+"obj/badge:";
}
drop() {
    return 1;
}
