/* Completed: 14.01.1995. */

#include "/players/aaa/defs.h"
#include <std.h>

inherit "room/room";
int counter;

void reset(int arg) {
    ::reset(arg);
    counter=6;
    if(arg) return;
    set_light(1);
    short_desc="Edge of a forest";
    long_desc="It seems that what you thought to be a grove, was the "+
        "very edge of a forest. From here you can turn back and return "+
        "to the road south, or, if you dare, you can take the risk of "+
        "getting lost and running into dangerious animals by going further.\n"+
        "You can hear roaring of wolfs from somewhere. Roaring of DYING "+
        "wolfs!\n";
    dest_dir=({PA+"area1/ewroad2.c","south",
               PA+"area1/forest1.c","forest"});
    items=({"tree","Just trees, nothing interesting.\nWait, it seems as if"+
                   " there was something interesting at the roots",
            "trees","Just trees, nothing interesting. Uhm, one tree is"+
                    " different from the others",
            "root","I guess, they are hiding something",
            "roots","I guess, they are hiding something"});   
}

void init() {
    ::init();
    add_action("search","search");
}

int search(string str) {
    object ob;
    if ((!str) || ((str!="root") && (str!="roots"))) {
        notify_fail("You can't find anything.\n");
        return 0;
    }
    if (counter>0) {
        counter=counter-1;
        ob=clone_object(PA+"area1/berry.c");
        transfer(ob,this_player());
        write("You find an appetizing blackberry!\n");
        return 1;     
    }
    write("Sure, there were some blackberries here...\nBut someone "+
          "has eaten them all!\n");
    return 1;
}
