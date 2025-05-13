#include "/sys/levels.h"
#include "/players/saffrin/guild/defs.h"

int main(string str) {

    object obj,weaker;
    int cost,duration;

    if(TP->LEVEL < 8) {
        write("You are not allowed to use this spell till level 8.\n");
        return 1;
    }

    if(!str) {
        write("Whom do want to hold ?\n");
        return 1;
    }

    cost = TP->LEVEL * 10 - TP->WIS;
    if(cost < 50) cost = 50;

    if(!obj = present(str,ENV(TP))) {
        write("That is not here.\n");
        return 1;
    }
    if(!living(obj)) {
        write("That is not a living thing.\n");
        return 1;
    }
/*
    if(obj->query_player()) {
        printf("You cannot use this on players.\n");
        return 1;
    }
 */
    if(TP->SP < cost) {
        write("You are not strong enough.\n");
        return 1;
    }

    duration = TP->CHA - obj->CHA;
    if(duration < 3) duration = 3;

    obj->hold(TP,duration);

    TP->ADDSP(-cost);

    return 1;
}

