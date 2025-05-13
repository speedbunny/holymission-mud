/* Completed 12.92.1995 */

#include "/players/aaa/defs.h"
#include <std.h>

inherit "room/room";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc="Berovang, Wizardry Avenue";
    long_desc="You slowly walk on the cobblestones of the Wizardry Avenue "+
              "in the prospering city of Berovang. Travellers, adventurers, "+
              "merchants and suspicious-looking people bustle around.\n"+
              "The road is framed by houses.\n";
    dest_dir=({PA+"ntown/square.c","east",
               PA+"ntown/street6.c","west"});
    items=({"house", "To the north, you can see the city hall. South is "+     
             "the pub. Too bad, you can't enter from here",         
             "houses", "To the north, you can see the city hall. South is "+  
             "the pub. Too bad, you can't enter from here"});
}

void init() {
    ::init();
}
