/* Completed 14.01.1995 */

#include "/players/aaa/defs.h"
#include <std.h>

inherit "room/room";

void reset(int arg) {
    object ob;
    ::reset(arg);
    ob=present("falcon");
    if (!ob || !living(ob)) {
        ob=clone_object(PA+"area1/falcon.c");
        move_object(ob,this_object());
    }
    ob=present("egg");
    if (ob && (!living(ob))) destruct(ob);
    if (arg) return;
    set_light(1);
    short_desc="East-west road, on a tree.";
    long_desc="You are sitting inside the crown of a tree. Dense branches"+
              " cover the view from your eyes. A large nest is located just"+
              " before you.\n";                            
    dest_dir=({PA+"area1/ewroad2.c","down"});
    items=({"nest","A large nest made of branches and mud. It is 3 "+
                   "meters [3 yards] in diameter",
            "branch","Thick branches, with a lot of leaves",
            "branches","Thick branches, with a lot of leaves"});
}
