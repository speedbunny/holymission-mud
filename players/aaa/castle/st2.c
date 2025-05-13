/* Completed 26.02.1995. */

#include "/players/aaa/defs.h"
#include <std.h>

inherit "room/room";

void reset(int arg) {
    object ob;
    ::reset(arg);
    ob=present("aaa-turtle");
    if ((!ob) || (!living(ob))) {
        ob=clone_object(PA+"castle/turtle");
        move_object(ob,this_object());
    }
    if(arg) return;
    property=({"no_teleport"});
    set_light(1);
    short_desc="Aaa's castle, south tower";
    long_desc="patience...\n";
    dest_dir=({PA+"castle/st1","down",
               PA+"castle/st3","up"});
    items=({ });   
}

void init() {
    ::init();
    add_action("up","up");
}

int up(string str) {
    if(str) {
        notify_fail("What ?\n");
        return 0;
    }
    if(present("aaa-turtle")) {
        write("The turtle doesn't let you to go up!\n");
        return 1;
    }
    this_player()->move_player("up#"+PA+"castle/st3.c");
    return 1;
}
