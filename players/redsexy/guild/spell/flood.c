#include "/include/defs.h"

int _main(string str) {       
    object whom, env;
    int dam,cost;
    
    env = environment(TP);
    dam =(TP->INT)+(TP->WIS)+(TP->LEVEL)+random(20);
    cost=10;
    whom=TP->query_attack();

   if(TP->LEVEL < 2){
        write("You cannot handle the element of water yet.\n");
        return 1;
    }

    if(env->query_property("no_fight")) {
        write("You cannot call the elements from within.\n");
        return 1;
    }

    if(!whom) {
        write("You need to be in a fight to call flood.\n");
        return 1;
    }
    
     write("You flood " + whom->NAME + " by calling on the power of water.\n");
    if(TP->SP < cost) {
        write("You do not have the power to direct the water you have called.\n");
        return 1;
    }
 
  write("The element of water floods " +
          whom->NAME + "!\n");
  say(TP->SNAME + " calls a Flood, taking the breath from " + whom->NAME + "!\n");

    whom->hit_player(1);
    whom->hit_player(dam);
    TP->ADDSP(-cost);
    return 1;
}

int main(string str) {
    call_out("_main",0,str);
    return 1;
}
