#include "/include/defs.h"

int _main(string str) {       
    object whom, env;
    int dam,cost;
    
    env = environment(TP);
    dam =(TP->INT)+(TP->WIS)+200;
    cost=50;
    whom=TP->query_attack();

    if(TP->LEVEL < 7){
        write("You cannot combine the elements correctly.\n");
        return 1;
    }

    if(env->query_property("no_fight")) {
        write("You cannot call the elements from within.\n");
        return 1;
    }

    if(!whom) {
        write("You need to be in a fight to call ice.\n");
        return 1;
    }
    
     write("You pelt " + whom->NAME + " with an Ice Storm.\n");
    if(TP->SP < cost) {
        write("Your energy runs low and the ice just melts to water.\n");
        return 1;
    }
 
  write("Wind and water combine into miniscule glacier spikes and pierce " +
          whom->NAME + ".\n");
  say(TP->SNAME + " calls an Ice Storm down upon " + whom->NAME + "!\n");

    whom->hit_player(1);
    whom->hit_player(dam);
    TP->ADDSP(-cost);
    return 1;
}

int main(string str) {
    call_out("_main",0,str);
    return 1;
}
