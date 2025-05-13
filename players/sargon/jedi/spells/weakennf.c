#include "/players/mangla/defs.h"

/********* WEAKEN Reduces the HP and SP and DEX of the opponent
                  to make damage higher and recieved hits weaken.
**********/

int main(string str) {

    object obj,weaker;
    int cost,percentage,duration;

    if(!str) {
        notify_fail("Whom do want to weaken ?\n");
        return 0;
    }
    cost = TP->LEVEL * 2 - TP->WIS;
    if(!obj = present(str,ENV(TP))) {
        notify_fail("That is not here.\n");
        return 0;
    }
    if(!living(obj)) {
       notify_fail("That is not a living thing.\n");
        return 0;
    }
    if(obj->query_player()) {
        printf("You cannot use this on players.\n");
        return 1;
    }
    if(!present("weakerobj",obj)) {
        if(TP->SP < cost) {
            notify_fail("You are not strong enough.\n");
            return 0;
        }
        duration = TP->CHA * 2 - obj->CHA;
        percentage = TP->LEVEL/4 * 10 + 5;
        weaker=clone_object("players/mangla/guild/weaker");
        move_object(weaker,obj);
        weaker->_start((int)duration,(int)percentage);
        write(obj->NAME + " looks less strong than before.\n");
        TP->ADDSP(-cost);
    }
    else {
        write(obj->NAME + " does not appear to be affected.\n");
        TP->ADDSP(-cost/3);
    }
    return 1;
}
