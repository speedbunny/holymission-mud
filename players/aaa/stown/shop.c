
/* Completed 12.02.1995 */

#include "/players/aaa/defs.h"
#include <std.h>

inherit "/obj/std_shop";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc="General store of Berovang";
    long_desc="This is the general store of Berovang. However, the interior "+
              "doesn't match the exterior: the whole place looks worn down."+
              "In fact, the furniture is nothing but crates: the counter is "+
              "just two crate (a smaller on a bigger), and the shopkeeper, "+
              "Greedy is sitting on another crate, and is waiting for you "+
              "to type 'list','buy','sell' or 'value'.\n";
    store=PA+"stown/store.c";
    keeper="Greedy";
    dest_dir=({PA+"stown/road6.c","west"});
    items=({"crate","There are plenty of them: open ones, closed ones, at "+
            "all parts of the room",
            "crates","There are plenty of them: open ones, closed ones, at "+
            "all parts of the room",
            "wall","Crumbling whitewashed walls",
            "walls","Crumbling whitewashed walls",
            "counter","just a smaller crate on a bigger one"});   
}

void init() {
    ::init();
}
