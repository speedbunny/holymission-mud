#include "/include/defs.h"

int _main(string str) {       
    object whom, env;
    int dam,cost;
    
    env = environment(TP);
    dam =((TP->INT)+(TP->DEX)+(TP->LEVEL)+(TP->WIS))*random(8);
    cost=20;
    whom=TP->query_attack();


    if(TP->LEVEL < 4){
        write("You cannot combine the elements correctly.\n");
        return 1;
    }

    if(env->query_property("no_fight")) {
        write("You cannot call the elements from within.\n");
        return 1;
    }

    if(!whom) {
        write("You need to be in a fight to call magma.\n");
        return 1;
    }
    
     write("You scorch " + whom->NAME + " with a blast " +
                  "of flame.\n");
 
     if(TP->SP < cost) {
        write("The magma fizzles into nothingness.\n");
        return 1;
    }
 
  write("Wind and fire form a blaze shooting down from above onto " +
          whom->NAME + ".\n");
  say(TP->SNAME + " combines wind and fire to call a blaze down on " + whom->NAME + "!\n");

    whom->hit_player(1);
    whom->hit_player(dam);
    TP->ADDSP(-cost);
    return 1;
}

int main(string str) {
    call_out("_main",0,str);
    return 1;
}
