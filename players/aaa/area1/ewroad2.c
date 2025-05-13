/* Completed 29.01.1995 */

#include "/players/aaa/defs.h"
#include <std.h>

inherit "room/room";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc="East-west road, in a forest.";
    long_desc="A beautiful grove. To the north, the trees get denser."+
              "Isn't it water-gurgling that you can hear from the south ?\n"+
              "One particular tree attracts your attention."+
              " You can see a top of a tower to the east.\n";
    dest_dir=({PA+"area1/forest0.c","north",
               PA+"area1/ewroad1.c","east",
               PA+"area1/ewroad3.c","west",
               PA+"area1/shore.c","south"});
    items=({"tower","A black tower, probably belongs to a building.  There "+
                    "is something on the top of it, shimmering in the "+
                    "sunshine",
            "top","There is something shiny on it, but you are too far yet "+
                  "to decide what it is",        
            "top of tower","There is something shiny on it, but you are too "+ 
                  "far yet to decide what it is",
            "tree","A century-old walnut tree, with some low branches"});   
}

void init() {
    ::init();
    add_action("climb","climb");
}

int climb(string str) {
     if(!str) {
         notify_fail("You try to climb in the air, but fail.\n");
         return 0;
     }
     if (str!="tree") {
        notify_fail("You can't climb that!\n");   
        return 0;
     }
     this_player()->move_player(" to the tree#/players/aaa/area1/tree.c");
     return 1;
}
