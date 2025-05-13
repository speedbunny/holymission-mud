/* Completed 29.01.1995 */

#include "/players/aaa/defs.h"
#include <std.h>

inherit "room/room";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc="East-west road.";
    long_desc="File has been corrupted, rewrite in progress.\n";
    dest_dir=({PA+"area1/ewroad2.c","east",
               PA+"ntown/street1.c","west"});
}