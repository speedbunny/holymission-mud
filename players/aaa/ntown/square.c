
#include "/players/aaa/defs.h"
#include <std.h>

inherit "room/room";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc="unfinished room";
    long_desc="unfinished room. Market will be here.\n";
    dest_dir=({PA+"ntown/road2.c","north",
               PA+"ntown/street4.c","east",
               PA+"stown/road3.c","south",
               PA+"ntown/street5.c","west"});
    items=({ });   
}

void init() {
    ::init();
}

