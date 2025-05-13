inherit "room/room";

#define FPATH "/players/tatsuo/area/rooms/"
#include "/players/tatsuo/area/tatsuo_defs.h"

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="The supervisor's office",
        long_desc=
"This is a spacious office.  On the east wall behind the desk is a map\n"+
"detailing the entire layout of all levels of the mine.  Shelves on the\n"+
"south and north walls hold many scrolls.  There is a closet in the\n"+
"southeast corner of the room.  A bucket of clean water, a sponge and a\n"+
"bar of soap set on a small table nest to the closet against the south\n"+
"wall.\n";
   dest_dir=({
            CAMPPATH+"legionnaire_corridor4","west",
         });
   items=({
  "wall","It was chipped out of stone",
  "desk","A large clean open desk",
  "table","A small table with soap and a bucket of water on it",
  "sponge","A clean sponge next to the soap",
  "bucket","A small bucket of water",
  "water","Water that looks recently changed",
  "scrolls","Wolfen notations about proposed tunnes and rock samples",
  "closet","A large wooden closet with a lock on it",
  "maps","Maps of the mine and proposed excavations",
  "shelves","Shelves that hold many different scrolls",
  });

        smell = "You smell nothing special.";
    }
}



