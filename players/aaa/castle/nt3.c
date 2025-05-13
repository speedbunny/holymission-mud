/* Completed 19.02.1995. */

#include "/players/aaa/defs.h"
#include <std.h>

inherit "room/room";

void reset(int arg) {
    object ob;
    ::reset(arg);
    property=({"no_teleport"});
    ob=present("orb");                    
    if (!ob || (living(ob))) {
        ob=clone_object(PA+"castle/orb.c");
        move_object(ob,this_object());
    }
    if(arg) return;
    set_light(1);
    short_desc="Aaa's castle, tower room";
    long_desc="This is the top room of the north tower. Seems if "+
              "no one was here in the last years that is not surprising "+
              "if you recall how hard was it to reach here. The furniture "+
              "is a table and a chair, nothing else.\n";
    dest_dir=({PA+"castle/nt2.c","down"});
    items=({"chair","Seems decayed, better if you don't sit on it",
            "table","A simple wodden table. There is a pillow on it",
            "pillow","Excellent place for an orb"}); 
}

void init() {
    ::init();
}                            
