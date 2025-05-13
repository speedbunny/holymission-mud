#include "/players/mangla/defs.h"

/******** DISCORD Causes all creatures attacking the player
                  to turn on each other.
*********/

int main(string str) {

    object *all;
    int i,percentage,w,cost,count;
    int j;

    all=all_inventory(ENV(TP));
    count=0;

    j=sizeof(all);
    cost=TP->LEVEL + j*8;
    if(TP->SP < cost) {
        write("You lack the mental energy to sow discord.\n");
        return 1;
    }
    TP->ADDSP(-cost);

    for(i=0; i<j; i++) {
        if(all[i]->short() && all[i]->query_attack() == TP && all[i]->query_guild() != 4) {
            w=random(sizeof(all));
            while ((all[w]==TP && !random(3)) || (w==i) || (!living(all[w])))
                w=random(sizeof(all));
            count++;
            all[i]->attack_object(all[w]);
        }
    }
    if(!count)
        write("Everybody here seems to do somethings else.\n");
    else
        write("You have sown the seeds of discord between your opponents.\n");
    return 1;
}

