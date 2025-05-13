/* Completed 25.02.1995 */

#include "/players/aaa/defs.h"
#include <std.h>

inherit "room/room";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    property=({"no_teleport"});
    set_light(1);
    short_desc="Aaa's castle, under south tower";
    long_desc="After a moment of thinking, you decide that this room is "+
              "the base of the south tower. And, really, you discover stairs "+
              "leading up. But, before going up, perhaps you should read the "+
              "SIGN that is fixed to the wall.\n";
    dest_dir=({PA+"castle/antecham.c","north",
               PA+"castle/st2.c","up" });
    items=({"wall","Made of very black marble. A sign is attached to it",
            "walls","Made of very black marble. A sign is attached to one of "+
                    "them",
            "stairs","Their material, if possible, is even darker than the "+
                     "walls'. Seems not too many people used them",
            "sign","Why, there are some writing on it"});   
}

void init() {
    ::init();
    add_action("read","read");
}

int read(string str) {
    if((str!="sign") && (str!="writing")) {
        notify_fail("Read what?\n");
        return 0;
    }
    write("It reads:\n\nCongrtulated with your bravery and intelligence!\n"+
          "If your combat skills are good enough to pass the monsters in "+
          "this tower, you\nwould prove your worthyness and would be welcome "+
          "in my workroom for a talk.\n"+
          "The first monster is sturdy, aggressive, but doesn't hit so hard.\n"+
          "The second one is weak and non-aggressive, but a real asskicker, "+
          "so beware!\n\nWizard Aaa\n");
    return 1;
}
