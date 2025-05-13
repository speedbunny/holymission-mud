/* Completed 29.01.1995 */

#include "/players/aaa/defs.h"
#include <std.h>

inherit "room/room";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc="East-west road, a castle is near.";
    long_desc="The dusty road arrives to a plane. You suddenly recognize "+
              "that no noise can be heared. Strange. There is a rock next "+
              "to the road.\n"+
              "You can see the towers of a castle east.\n";
    dest_dir=({PA+"area1/ewroad2.c","west",
               PA+"area1/a_castle.c","east"});
    items=({"rock","Just a simple rock. But perhaps you can move it",
            "castle","It has three towers. The middle is higher than the "+
            " others",
            "tower","Please, be more specific, there are three: left, right "+
                    "and middle",
            "towers","There are three of them",
            "left tower","Nothing interesting",
            "right tower","Nothing interesting",
            "middle tower","Darn, there is a huge upside-down cross on the "+
            " top of it! It's not late yet to turn back",
            "cross","Its height is 7 meters [22 feet], width is 3 meters"+     
                    " [10 feet], and seems to be made of GOLD. Some birds "+   
                    "are circling around it",                                  
"upside-down cross","Its height is 7 meters [22 feet], width is 3 meters"+     
                    " [10 feet], and seems to be made of GOLD. Some birds "+   
                    "are circling around it",                                  
            "birds","You can't make out from here what kind they are"});
}

void init() {
    ::init();
    add_action("push","push");
    add_action("push","move");
}

int push(string str) {
    if (!str) {
        notify_fail("You make some gymnastical exercises.\n");
        return 0;
    }
    if (str!="rock") {
        notify_fail("Better to leave that in peace!\n");
        return 0;
    }
    write("No, you can't move that... It weights more than 1000 kgs "+
          "[2200 pounds].\n");
    return 1;
}   
