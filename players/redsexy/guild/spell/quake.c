#include "/include/defs.h"

int _main(string str) {       
    object whom, env;
    int dam,cost;
    
    env = environment(TP);
    dam =(TP->INT)+(TP->WIS)+(TP->LEVEL)+random(60);
    cost=30;
    whom=TP->query_attack();


   if(TP->LEVEL < 4){
        write("You cannot handle the element of earth yet.\n");
        return 1;
    }

    if(env->query_property("no_fight")) {
        write("You cannot call the elements from within.\n");
        return 1;
    }

    if(!whom) {
        write("You need to be in a fight to call quake.\n");
        return 1;
    }
    
     write("You concentrate your powers on the earth around " + whom->NAME + ".\n");
    if(TP->SP < cost) {
        write("You are unable to manipulate the earth at this point.\n");
        return 1;
    }
 
  write("The ground starts to shake and break around " +
          whom->NAME + "!\n");
  say(TP->SNAME + " calls a Quake in the area around " + whom->NAME + "!\n");

    whom->hit_player(1);
    whom->hit_player(dam);
    TP->ADDSP(-cost);
    return 1;
}

int main(string str) {
    call_out("_main",0,str);
    return 1;
}
