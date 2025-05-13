inherit "room/room";
#include "/players/blade/area/blade_defs.h"

#define FPATH "/players/blade/area/rooms/"

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="The guard captain's quarters",
        long_desc=
"This bedroom contains a wooden bed against the east wall, above which is\n"+
"fastened two shelves containing scrolls in leather cases.  At the foot of\n"+
"the bed is a padlocked chest, and a locker.  A bucket of clean water, a\n"+
"sponge and a bar of soap are sitting on a small table with a chair against\n"+
"the north wall.\n";
   dest_dir=({
// Mangla changed to fix bug. Also do not need .c on end of path.
            CAMPPATH+"guards_quarters","north"
         });
   items=({ 
  "bed","A comfortable looking wooden bed",
  "cases","Protective cases for the scrolls",
  "locker","A sturdy metal locker",
  "bedroom","This is the guard captain's bedroom",
  "desk","A large clean open desk",
  "chair","A small wooden chair",
  "table","A small table with soap and a bucket of water on it",
  "sponge","A clean sponge next to the soap",
  "bucket","A small bucket of water",
  "water","Water that looks recently changed",
  "scrolls","Romanticized military histories of the capatin's exploits",
  "chest","A sturdy wooden chest that lies at the end of the bed",
 });
        smell = "You smell nothing special.";
    }
}




