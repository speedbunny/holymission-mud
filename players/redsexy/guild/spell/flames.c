#include "/include/defs.h"

int _main(string str) {       
    object whom, env;
    int dam,cost;
    
    env = environment(TP);
    dam =(TP->INT)+(TP->WIS)+(TP->LEVEL)+random(80);
    cost=40;
    whom=TP->query_attack();


   if(TP->LEVEL < 5){
        write("You cannot handle the element of fire yet.\n");
        return 1;
    }

    if(env->query_property("no_fight")) {
        write("You cannot call the elements from within.\n");
        return 1;
    }

    if(!whom) {
        write("You need to be in a fight to call flames.\n");
        return 1;
    }
    
     write("You concentrate your powers and call forth flames towards " + whom->NAME + ".\n");
    if(TP->SP < cost) {
        write("The flames burn out before reaching their target.\n");
        return 1;
    }
 
  write("The flames burn " +
          whom->NAME + "with a ferocious intensity!\n");
  say(TP->SNAME + " calls Flames which scorch " + whom->NAME + "!\n");

    whom->hit_player(1);
    whom->hit_player(dam);
    TP->ADDSP(-cost);
    return 1;
}

int main(string str) {
    call_out("_main",0,str);
    return 1;
}
