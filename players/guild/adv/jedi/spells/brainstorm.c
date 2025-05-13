#include "/players/mangla/defs.h"

/****** BRAINSTORM  If the monster is low on HP and hurting,
                    Brainstorm can be used to finish it off
                    quickly. If successful, an insta-kill is
                    scored.
******************/

int main(string str) {

    int     targhp, targmaxhp, cost;
    object  target;
    object obj;

    if(!str) {
        obj = TP->query_attack();
        if (obj) {
        str = (obj)->query_name();
        }
        else {
            write("You must choose a target.\n");
            return 1;
        }
        str = lower_case(str);
    }

    target = present(str,ENV(TP));

    if(!target || !living(target)) {
        write("There is no " + str + " here to brainstorm !!.\n");
        return 1;
    }

    if (TP->LEVEL < 10) write("You need to gain more experience first.\n");

    cost = 10 + TP->LEVEL*2 - TP->WIS;
    targhp = target->HP;
    targmaxhp = target->MAXHP;

    if(TP->SP < cost) {
        write("You do not have the strength to do that now.\n");
        return 1;
    }

    if( ((100*targhp/targmaxhp) - TP->LEVEL) < 10 ) {
        write("You concentrate really hard.\n");
        if((random(TP->CHA)+TPL) > random(50)) {
            write("You manange to overpower " + target->NAME +
                  "'s natural defenses and\n" +
                  "shut down its brain, instantly killing it.\n");
            say(target->NAME + " suddenly goers still.\n" +
                "It is " + BOLD + "dead." + RESET + "\n");
            target->misc_hit(100000,7);
        }
        TP->ADDSP(-cost);
    }
    else {
        write("You concentrate, but fail to penetrate your " +
              "opponents defenses.\n");
        TP->ADDSP(-cost/3);
    }
    return 1;
}

