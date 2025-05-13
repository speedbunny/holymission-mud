inherit "room/room";
#include "/players/blade/area/blade_defs.h"

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="A small enclave in the courtyard",
        long_desc=
  "The courtyard is swarming with activity.  There is a bit less activity \n" +
  "in this area.  The building to the south is open to this direction.\n"+
  "A small shed lies to the west.  North the courtyard ends, and a tunnel\n"+
  "leads underground.\n";
   dest_dir=({
            CAMPPATH+"legionnaire_corridor1.c","north",
	    CAMPPATH+"carpenter_area.c",       "south",
	    CAMPPATH+"encampment5.c",          "east",
	    CAMPPATH+"new_tool_shed.c",        "west",
         });
   items=({ 
   "southern building","A building which you are curious as to what is inside",
   "building","A building which you are curious as to what is inside",
   "shed","A small shed, probably used for storage",
 });

        smell = "You smell nothing special.";
    }
}



