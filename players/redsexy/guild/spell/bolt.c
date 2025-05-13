#include "/include/defs.h"

int _main(string str) {       
    object whom, env;
    int dam,cost;
    
    env = environment(TP);
    dam =(TP->INT)+(TP->WIS)*10;
    cost=50;
    whom=TP->query_attack();

    if(TP->LEVEL < 22){
        write("You do not know how to use power correctly.\n");
        return 1;
    }

    if(env->query_property("no_fight")) {
        write("You cannot call the elements from within.\n");
        return 1;
    }

    if(!whom) {
        write("You need to be in a fight to call forth a bolt.\n");
        return 1;
    }
    
     write("You summon forth a bolt of raw energy from the skies!\n");
    if(TP->SP < cost) {
        write("Your energy runs low and the bolt does not reach the target.\n");
        return 1;
    }
 
  write("The power surges down upon " +
          whom->NAME + ".\n");
  say(TP->SNAME + " calls a raw Bolt of power down upon " + whom->NAME + "!\n");

    whom->hit_player(1);
    whom->hit_player(dam);
    TP->ADDSP(-cost);
    return 1;
}

int main(string str) {
    call_out("_main",0,str);
    return 1;
}
