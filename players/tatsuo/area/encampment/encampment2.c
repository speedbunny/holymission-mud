inherit "room/room";

#include "/players/tatsuo/area/tatsuo_defs.h"

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="The courtyard",
        long_desc=
  "The courtyard is swarming with activity.  You see wolfen carrying\n" +
  "parcels here and there.  You hear the sounds of people eating\n"+
  "and drinking coming from a door in the building in the west.  The\n"+
  "entrance to the mine is far to the north, and the gate to the encampment\n"+
  "lies to the south.  A more silent building lies to your east.  Wolfen\n"+
  "guards are patroling the courtyard.\n";
   dest_dir=({
            CAMPPATH+"encampment3.c", "north",
	    CAMPPATH+"encampment1.c", "south", 
	    CAMPPATH+"mess_hall.c",   "west"
                 });
   items=({ 
     "palisade","A large 18ft wall which encircles the encampment.  A wolfen guard stands on top",
     "guard","A large burly wolfen guard who eyes you warily",
     "wolfen guard","A large burly wolfen guard who eyes you warily",
     "western building","It looks like a mess hall",
     "eastern building","A large building with a door to the northeast",
     "building","Which one?",
     "mine","Its too far away to see any details",
     "parcels","Small packages that are being brought to a building in the north",
     "courtyard","An open area measuring at 40ft wide and 70ft long at its longest point",
   });

        smell = "You smell some sort of food coming from your west.";
    }
}



