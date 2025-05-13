#include "/players/mangla/defs.h"

/******* NOATTACK Causes all creatures in the room to peace
                  Helpful to allow jedi to heal.
********/

int query_delay() {
  return 3;
}



int perform_noattack(object obj) {

    object env, *ob;
    int i, j;

    env = ENV(TP);
    if(env != obj)
        return 1;
    ob = all_inventory(env);
    j = sizeof(ob);
    for (i=0; i<j; i++) {
        if (living(ob[i]) && ob[i]->query_attack()) {
            if(ob[i]->CHA < TP->CHA * 3 + TP->LEVEL) {
                ob[i]->stop_fight();
                ob[i]->stop_fight();
                ob[i]->stop_hunter(1);
            }
            else
                write("You cannot affect " + ob[i]->NAME + ".\n");
        }
    }
    write("You're no longer attacked.\n");
    return 1;
}

int main() {

    write("You concentrate your Force.\n");
    say(TP->NAME + " utters some strange words.\n");
    perform_noattack(ENV(TP));
    return 1;
}

