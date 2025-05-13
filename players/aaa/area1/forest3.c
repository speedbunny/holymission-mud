
/* Completed 14.01.1995 */

#include "/players/aaa/defs.h"
#include <std.h>

inherit "room/room";

void reset(int arg) {
    object ob;
    ::reset(arg);
    ob=present("mushroom");
    if ((!ob) || living(ob)) {
        ob=clone_object(PA+"area1/mushr3.c");
        move_object(ob,this_object());
    }
    if(arg) return;
    set_light(1);
    short_desc="Dense forest";
    long_desc="You are walking somewhere in a dense forest. The trees have "+
            "grown so dense that teir branches let down very few light. You "+
            "can hardly see. Thick bushes make walking difficult.\n"+
            "Blood-curdling roaring can be heared from the distance.\n";
    items=({"tree","Oaks, platans, maples... nothing interesting",
            "trees","Oaks, platans, maples... nothing interesting",
            "bush","You are not a botanic, can't identify any of them",
            "bushes","You are not a botanic, can't identify any of them"});
    dest_dir=({PA+"area1/forest0.c","go"}); /* obv. exits leads randomly,
                                               cf. function "go". Just had
                                               to write something here. */   
}

void init() {
    ::init();                                       
    add_action("go","go");
}

int go(string str) {
    int i;
    string *r;    
    if(!str) {
          r=allocate(10);
          r=({"0","1","2","3","4","5","6","7","8","9"});
          i=random(10);
          this_player()->move_player(" somewhere#"+PA+"area1/forest"+r[i]);
    return 1;
    }
    notify_fail("Pardon ?");
    return 0;
}
