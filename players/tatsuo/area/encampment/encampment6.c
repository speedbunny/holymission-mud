inherit "room/room";
#include "/players/tatsuo/area/tatsuo_defs.h"

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="The courtyard",
        long_desc=
  "The courtyard is swarming with activity.  You see wolfen carrying\n" +
  "parcels here and there.   The entrance to the mine lies directly north\n"+
  "Cart tracks lead north and east.\n";
   dest_dir=({
            L1PATH+"mt1", "north",
	    CAMPPATH+"encampment5", "south",
	    CAMPPATH+"encampment9", "east",
                 });
   items=({ 
     "guard","A large burly wolfen guard who eyes you warily",
     "wolfen guard","A large burly wolfen guard who eyes you warily",
     "mine","A dark opening in the hillside",
     "tracks","Tracks used to push carts along",
     "cart tracks","Tracks used to push carts along",
     "parcels","Small packages that are being brought to a building in the north",
     "courtyard","An open area measuring at 40ft wide and 70ft long at its longest point",
   });
        smell = "You smell nothing special.";
    }
}



