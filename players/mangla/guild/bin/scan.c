/*** DO NOT TOUCH THIS FILE WITHOUT TALKING TO ME FIRST.
     -Mangla
 ***/
#include "/players/mangla/defs.h"

/******** SCAN for the jedis to see all items
               in a room without a torch.
               Can sense invis objects.
*********/

int query_delay() {
  return 0;
}


int main(string str) {

    object room,obj;
    object *looks;
    object lookat;
    int count, found;

    if(!str) {
        room=ENV(TP);
        write("You concentrate the Force.\nIn your mind you can see:\n\n");
        room->set_light(5);
        room->long();
        room->set_light(-5);
        count=0;
        obj=first_inventory(room);
        while(obj) {
            if(obj!=TP && obj->short())
                write(obj->short()+".\n");
            if(obj->query_invis() && !obj->query_immortal()) {
              write("(" + CAP(obj->RNAME) + ")\n");
            }
/*
            if(((obj->query_invis() >= TP->LEVEL) || !obj->short())
                         && obj!=TP)
                count++;
 */
            obj=next_inventory(obj);
        }
/*
        if(count)
            write("You feel the presence of something you can't see.\n");
 */
        return 1;
    }

   if (str == "skip") return 0;

    if(sscanf(str,"at %s",str)!=1) return 0;
    write("You close your eyes and see:\n");
    found = 0;
    looks = all_inventory(TP);
    count = sizeof(looks);
    while(count) {
        count--;
        if(looks[count]->id(str)) {
            looks[count]->long();
            found = 1;
            break;
        }
    }
    if(!found) {
        looks = all_inventory(ENV(TP));
        count = sizeof(looks);
        while(count) {
            count--;
            if(looks[count]->id(str)) {
                looks[count]->long();
                found = 1;
                break;
            }
        }
    }
    if(!found) {
    write("You do not see that object here.\n");
    }

    return 1;
}

