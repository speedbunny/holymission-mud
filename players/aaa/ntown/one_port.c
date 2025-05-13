
#include "/players/aaa/defs.h"
#include <std.h>

inherit "room/room";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc="unfinished room";
    long_desc="unfinished room\nThe quest-portal will be here.\n";
    dest_dir=({PA+"ntown/road1.c","south"});
    items=({ });   
}

void init() {
    ::init();
}

