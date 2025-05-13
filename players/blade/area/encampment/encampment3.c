inherit "room/room";

#include "/players/blade/area/blade_defs.h"

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="The courtyard",
        long_desc=
  "The courtyard is swarming with activity.  You see wolfen carrying\n" +
  "parcels here and there.  A well has been built in the middle of the\n"+
  "courtyard.  A  door opens into in the building in the east.  The\n"+
  "entrance to the mine is far to the north, and the gate to the encampment\n"+
 "lies to the far south.  A guard stands beside the entrance to the western\n"+
  "building.  Wolfen guards are patroling the courtyard.\n";
   dest_dir=({
            CAMPPATH+"encampment4.c", "north",
	    CAMPPATH+"encampment2.c", "south", 
	    CAMPPATH+"horse_stables.c","east",
	    CAMPPATH+"grain_storehouse.c","west",
                 });
   items=({ 
     "guard","A large burly wolfen guard who eyes you warily",
     "wolfen guard","A large burly wolfen guard who eyes you warily",
     "western building","It looks like a storage building",
     "eastern building","A large building with a door",
     "building","Which one?",
     "mine","Its too far away to see any details",
     "parcels","Small packages that are being brought to a building in the north",
     "courtyard","An open area measuring at 40ft wide and 70ft long at its longest point",
   });

        smell = "You smell nothing special.";
    }
}


