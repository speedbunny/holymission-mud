#include "/include/defs.h"

int main(string str) {

    object targ;
    int cost;

    targ = present(str,ENV(TP));
    cost = TP->LEVEL*2;

    if(TP->LEVEL < 8){
        write("You cannot combine the elements correctly.\n");
        return 1;
    }

   if(!targ) {
        write("You can only call a Cyclone if " +CAP(str)+" is here.\n");
        return 1;
    }

    if(targ == TP) {
        write("You call a cyclone down on yourself, which ruffles your hair playfully.\n");
        say(TP->NAME + " calls a cyclone on themselves, messing up " + TP->POS + " hair!\n");
        return 1;
    }

    if(!living(targ)) {
        write("You try to call a cyclone on "+CAP(str)+", a harmless inanimate object.\n");
        return 1;
    }

    if(targ->query_real_guild() == 9 && targ->LEVEL > TP->LEVEL - 2) {
        write(targ->NAME + "can control the elements just as well as you can.\n");
        TELL(targ,TP->NAME + " tried to call a Cyclone down on you!\n");
        return 1;
    }

    if(targ->query_wimpy() < 0) {
        write("The " + targ->NAME + " stands steady in the cyclone.\n");
    }
    write("You combine earth and wind to call a cyclone!\n");
    say(TP->NAME + " combines the elements of earth and wind to call a cyclone!\n");
    TELL(targ,"You are caught in a powerful cyclone summoned by " + TP->NAME +
              ".\n" + "You are blown somewhere different!\n" );

    targ->run_away();

    if(ENV(targ) == ENV(TP)) {
        write("The monster is not effected by your cyclone!.\n");
    }
    return 1;
}

