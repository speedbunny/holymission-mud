#include "/players/mangla/defs.h"
inherit "/obj/armour";

int _return(string str) {

    if(!str && str != "home") {
        notify_fail("Return where?\n");
        return 0;
    }
    else {
        printf("You concentrate on the force and move yourself.\n");
        TP->MOVEP("suddenly#players/mangla/guild/rooms/inner");
        destruct(TO);
    }
    return 1;
}

int drop(string str) {

    destruct(TO);
    return 1;
}

void reset(int arg) {
   ::reset (arg);
   if (!arg) {
      set_alias("return");
      set_value(0);
      set_weight(0);
      set_size(0);
      set_ac(1);
      set_type("armour");
   }
}

void init() {

    ::init();
    add_action("_return","return");
}
