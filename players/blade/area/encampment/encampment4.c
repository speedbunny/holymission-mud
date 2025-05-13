inherit "room/room";

#include "/players/blade/area/blade_defs.h"

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="The courtyard",
        long_desc=
  "The courtyard is swarming with activity.  You see wolfen carrying\n" +
  "parcels here and there.  Loud clanking noises are coming out of the\n"+
  "doorway in the eastern building.  The entrance to the mine is far to the\n"+
  "north, and the gate to the encampment\n"+
  "lies to the far south.  To the west lies the wall of a large building.\n"+
  "Wolfen guards are patroling the courtyard.\n";
   dest_dir=({
            CAMPPATH+"encampment5.c", "north",
	    CAMPPATH+"encampment3.c", "south", 
	    CAMPPATH+"blacksmith.c",  "east",
                 });
   items=({ 
     "guard","A large burly wolfen guard who eyes you warily",
     "wolfen guard","A large burly wolfen guard who eyes you warily",
     "western building","A building to which you cannot immediately detect the door",
     "wall","The wall to the western building",
     "eastern building","A smaller building which houses working blacksmiths",
     "building","Which one?",
     "mine","Its too far away to see any details",
     "parcels","Small packages that are being brought to a building in the north",
     "courtyard","An open area measuring at 40ft wide and 70ft long at its longest point",
   });

        smell = "You smell nothing special.";
    }
}



