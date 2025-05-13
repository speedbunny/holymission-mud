
/*==========================================================================
	KNOCKOUT (moster) --- This spell will knockout out there openent
		for an amout of time depending upon level.
==========================================================================*/

#include <defs.h>

#define COST            10
#define MIN_LEVEL       20

int main(string str) {
    int    rnd, time;
    object ob;
    
    if(TP->LEVEL < MIN_LEVEL || TP->SP <= COST) {
        write("You are too weak to knock anything out.\n");
        return 1;
    }
    else if(!str || str == "")
        ob = TP->query_attack();
    else
        ob = present(str, ENV(TP));
        
    if(!ob || !living(ob)) {
        write("Knockout whom?\n");
        return 1;
    }    
    else if(interactive(ob) && ob->query_immortal()) { 
        printf("You can't knockout %s.\n", CAP(str));
        return 1;
    }
    else if(ob->query_npc()) {
        time = (TP->query_str()*2)+TP->query_dex();
        time = ((time/3)+1)*10;
        time /= ob->query_con();
    }
    else {
        time = (TP->query_str()*2)+TP->query_dex();
        time = ((time/3)+1)*5; 
        time /= (ob->query_con()+4); 
    }
     
    rnd = random(2*time/3);
    time = time/3 + rnd;
    if(TP->query_legend_level())
        time *= 2;             
    
    if(time > 0) {
        ob->hold(0, time);
        printf("You knockout %s.\n", ob->NAME);
        TP->ADDSP(-COST);
        if(TP->IMM)
            printf("Time (Wizinfo): %d\n", time);
        tell_object(ob, TP->NAME+" knocks you out.\n");
        say(TP->NAME+" knocks "+ob->NAME+" out.\n", ob);
    }
    else {
        printf("You try to knockout %s, but %s seems unaffected.\n",
               ob->NAME, ob->PRO);
        TP->ADDSP(-COST/2);
    }
    return 1;
}
