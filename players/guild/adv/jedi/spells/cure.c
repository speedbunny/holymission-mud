/*** DO NOT TOUCH THIS FILE WITHOUT TALKING TO ME FIRST.
     -Mangla
 ***/
#include "/players/mangla/defs.h"

/****** CURE Cures the players wounds 20% of max HP at a time.
             Will also remove all alcohol and poison from system.
********/

int main(string str) {

    int i, a;

    if(!str) return 0;


    if (str == "wounds") {
        if ((4*TP->MAXHP/5) < TP->HP) {
            write("Your wounds are not serious enough at this time to heal.\n");
            return 1;
        }
        else {
            a = TP->MAXHP/5;
            if (TP->SP < a/2) {
                write("You do not have the energy to heal yourself.\n");
                return 1;
            }
            if (TP->SP < a) a = TP->SP;
            TP->ADDHP(a);
            TP->ADDSP(-(3*a)/4); 
//            TP->ADDSP(-a);
            write("You feel better now!\n");
        }
    }

    if (str == "poison" || str == "alcohol") {
        a = TP->query_poisoned() * 2 + TP->query_intoxination() * 2/3;
        if(!TP->query_poisoned() && !TP->query_intoxination()) {
            write("You are not poisoned or intoxicated.\n");
            return 1;
        }
        if(TP->SP < a) {
            write("You lack the power to do that.\n");
            return 1;
        }
        write("You concentrate your Force.\n"+ 
              "You think your blood is boiling.\n");
/*
        if(TP->HP > 10)
            TP->ADDHP(-10);
 */
        TP->add_poison(-TP->query_poisoned());
        for (i=0; i < TP->query_intoxination(); i++)
            TP->add_intoxination(-1);
        TP->ADDSP(-a);
        return 1;
    }
    return 1;
}

