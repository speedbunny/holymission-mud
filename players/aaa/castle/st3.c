
#include "/players/aaa/defs.h"
#include <std.h>

inherit "room/room";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc="unfinished room";
    long_desc="unfinished room\n";
    dest_dir=({PA+"castle/st2.c","down"});
    items=({ });   
}

void init() {
    ::init();
}

