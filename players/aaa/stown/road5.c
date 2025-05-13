
#include "/players/aaa/defs.h"
#include <std.h>

inherit "room/room";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc="Berovang, Merchant Street";
    long_desc="You slowly walk on the cobblestones of the Merchant Street "+
              "in the prospering city of Berovang. Travellers, adventurers, "+
              "merchants and suspicious-looking people bustle around.\n"+
              "The road is framed by houses.\n";
    dest_dir=({PA+"stown/road4.c","north",
               PA+"stown/road6.c","south"});
    items=({"house", "The houses show the wealth of their "+                   
            "owners and usually have shops in their ground-floor. Everyone "+  
            "can find something worth to buy in these shops, probably "+       
            "including you",                                                
            "houses", "The houses show the wealth of their "+                   
            "owners and usually have shops in their ground-floor. Everyone "+  
            "can find something worth to buy in these shops, probably "+       
            "including you"});   
}

void init() {
    ::init();
}
