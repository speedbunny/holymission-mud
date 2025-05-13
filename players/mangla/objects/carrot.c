inherit "obj/food";
#include "/players/mangla/defs.h"

int _eat(string str) {

    if (str == "carrot")
        if (TP->MAXHP - TP->HP >=5)
            TP->ADDHP(5);
    else return 0;
    return 1;
}

reset (arg) {
    ::reset (arg);
    if (!arg) {
        set_name("carrot");
        set_short("Fresh Carrot");
        set_alias("carrot");
        set_long("Nice, juicy orange carrot.\n");
        set_value(0);
        set_weight(1);
    }
}

init() {
    ::init();
    add_action("_eat","eat");
}
