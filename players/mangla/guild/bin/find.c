#include "/players/mangla/defs.h"

/********** FIND Allows jedis to locate other players
                 on the mud. Does not work on wizards.
***********/

int query_delay() {
  return 0;
}


int main(string str) {

    object  where, obj;
    object  *inven;
    int     count, i, j;

    if(!str) return 0;

    obj=find_living(str);

    if(!obj) {
        write("You concentrate hard, but you fail to find " + CAP(str) + ".\n");
        return 1;
    }
    else {
        if(obj->query_immortal()) {
            write("Spying on the local gods is not healthy so you " +
                  "decide not to do it.\n");
            return 1;
        }
        write("You close your eyes and let the Force search for " + CAP(str) +
              ".\n" + CAP(obj->PRO) + " is at :\n");
        where=ENV(obj);
        if(!where) {
            write("You don't see anything.\n");
            return 1;
        }
        where->set_light(5);

        where->long();
        where->set_light(-5);
        if(!obj->query_npc() && !TP->query_immortal())
            write(obj->NAME+" is a Player.\n");
        inven = all_inventory(where);
        count = 0;
        j = sizeof(inven);
        for(i = 0; i < j; i++) {
            if(TP->query_immortal() && TP->LEVEL >= inven[i]->query_invis()) {
                write(inven[i]);
                write("\t" + inven[i]->query_name());
                if(inven[i]->query_real_name())
                    write("\t(" + inven[i]->query_real_name() + ")\n");
                else write("\n");
            }
            else if (!inven[i]->query_immortal() && inven[i] != obj)
                count++;
        }
        if (count && !TP->query_immortal())
             printf("You sense %d other object<s> in that room also.\n",count);
        else if(!TP->query_immortal())
            printf("You sense no one else in the room.\n");

        return 1;
    }
}

