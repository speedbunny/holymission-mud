/*** DO NOT TOUCH THIS FILE WITHOUT TALKING TO ME FIRST.
     -Mangla
 ***/
#include "/players/mangla/defs.h"

int _main(string str) {       /*** BOLT Used to send a quick
                                        burst of energy at your
                                        opponent.          *********/
    object whom;
    int dam,cost;

    object env;
    env = environment(TP);
    if(env->query_property("no_fight")) {
        write("You cannot harm anyone in this place.\n");
        return 1;
    }
    dam=20+TP->LEVEL/3+TP->WIS;
//    dam=20+TP->LEVEL/3+TP->WIS;
    cost=1-TP->INT/3+TP->LEVEL;
//    cost=30-TP->INT/3+TP->LEVEL;
    if(!str) whom=TP->query_attack();
    else whom=present(str,ENV(TP));

    if(!whom) {
        if(!str) write("Bolt whom?!\n");
        else write("No " + CAP(str) + " here.\n");
            return 1;
    }
    if(whom==TP) {
        write("You don't want to do that.\n");
        return 1;
    }
    if(!living(whom)) {
        write(CAP(str)+" is not a living thing.\n");
        return 1;
    }

    write("You hold your hands towards " + whom->NAME + ".\n");
    if(TP->SP < cost) {
        write("You lack the Force to finish the spell.\n");
        return 1;
    }
    write("Blue flashes of electricity crackle out of your hands and strike " +
          whom->NAME + ".\n");
    say("Bolts of electricity crackle out of " + TP->NAME + "'s hands and strike "+
        whom->NAME + ".\n");
//    if(whom->HP<dam) dam=whom->HP/2;
    whom->hit_player(1);
    whom->hit_player(dam,5);
    TP->ADDSP(-cost);
    return 1;
}

int main(string str) {
    call_out("_main",0,str);
    return 1;
}

