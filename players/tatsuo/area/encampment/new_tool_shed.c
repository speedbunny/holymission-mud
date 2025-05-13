inherit "room/room";
#include "/players/tatsuo/area/tatsuo_defs.h"

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="The new tool storage shed",
        long_desc=
"A small shed.  It contains newly made tools, crafted by the carpenters\n"+
"and the blacksmiths.  Axe handles, picks, and shovels are stacked neatly\n"+
"in seperate piles.\n";
   dest_dir=({
            CAMPPATH+"encampment7.c", "east",
                 });
   items=({ 
   "handles","Plain wooden handles",
   "axe handles","Plain wooden handles",
   "picks","Newly made mining picks"
   "shovels","New sturdy looking shovels",
   "shed","It measures 10ft by 15ft, and has little light in it",
   });

        smell = "You smell nothing special.";
    }
}



