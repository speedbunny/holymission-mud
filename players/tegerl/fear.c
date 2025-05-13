#include "/players/mangla/defs.h"

/******** FEAR Scares the opponent out of the room.
               Possibility of legend level to scare opponent stiff.
*********/

int main(string str) {

    object targ;

    if(!str) {
        write("Whom do you want to fear?\n");
        return 1;
    }

    targ = present(str,ENV(TP));
    if(!targ) {
        write(CAP(str)+" isn't here.\n");
        return 1;
    }
    if(targ == TP) {
        write("You don't really want to do that.\n");
        return 1;
    }
    if(!living(targ)) {
        write(CAP(str)+" is actually not a living thing.\n");
        return 1;
    }
    if(targ->query_guild() == 4 && targ->LEVEL > TP->LEVEL - 2) {
        write(targ->NAME + " is a Jedi, too. You cannot fake " + targ->PRO + ".\n");
        TELL(targ,TP->NAME + " tries to fear you.\n");
        return 1;
    }
    if(targ->WIS - 20 > (TP->WIS + TP->CHA)) {
        write(targ->NAME + " is to wise to fall for that.\n");
        return 1;
    }
    if(targ->query_wimpy() < 0) {
        write("The " + targ->NAME + " is too foolhardy to be afraid of you.\n");
    }
    write("You concentrate your Force and say some words.\n");
    say(TP->NAME + " speaks some strange words and waves with a hand.\n");
    TELL(targ,"As you look up to " + TP->NAME + " you get an unusual "+
             "feeling.\nYour hands begin to sweat.\nYou panic.\n");
    if(TP->query_legend_level() && (targ->LEVEL < L_APPR )
                                && random(2)) {
        write("You fear the beast so bad that it freezes in fear.\n");
        targ->hold(TP,30);
        return 1;
    }
    targ->run_away();
    if(ENV(targ) == ENV(TP)) {
        write("The monster does not flee.\n");
    }
    return 1;
}

