inherit "room/room";

#define FPATH "/players/blade/area/rooms/"
#include "/players/blade/area/blade_defs.h"

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="The supervisor's quarters",
        long_desc=
  "A comfortable bedroom.  In the center is a small tent made out of bed\n"+
  "sheets.  Inside this tent, is a cushion, made up like a bed, and a few\n"+
  "flat stones, covered with cloth, for furniture.\n";
   dest_dir=({
            CAMPPATH+"supervisor_quarters2.c","south",
	    CAMPPATH+"legionnaire_corridor3.c","east",
         });
   items=({ 
  "bedroom","This is the mine supervisor's bedroom",
  "tent","A 4ft x 2ft and 2ft tall tent made of bed sheets",
  "cushion","It looks like the supervisor's bed",
  "flat stones","Stones covered in cloth for guests to sit on",
  "cloth","Expensive looking cloth",
  });
        smell = "You smell nothing special.";
    }
}




