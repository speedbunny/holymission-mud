inherit "room/room";

#include "/players/blade/area/blade_defs.h"

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="The courtyard",
        long_desc=
  "The courtyard is mostly out of sight.  Many wolfen walk in and out of\n"+
 "the place to the south.  Cart tracks go west and south into the building.\n"+
 "You also notice smoke coming out of the building.\n";
   dest_dir=({
	    CAMPPATH+"ore_refining_area.c", "south",
	    CAMPPATH+"encampment6.c", "west",
                 });
   items=({ 
     "building","A building with smoke pouring out of the chiminey",
     "tracks","Tracks used to push carts along",
     "cart tracks","Tracks used to push carts along",
   "parcels","Small packages that are being brought out of the refining area",
     "courtyard","It is no longer in sight",
   });
        smell = "You smell nothing special.";
    }
}



