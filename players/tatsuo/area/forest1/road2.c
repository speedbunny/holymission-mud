inherit "room/room";

#include "/players/tatsuo/area/tatsuo_defs.h"

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="A long road through a small valley",
        long_desc=
            "This road is well worn with the grooves of cart tracks.  It\n" +
	    "climbs a hill in the near distance.\n";     
   dest_dir=({
            F1PATH+"road3.c", "west",
	    F1PATH+"road1.c", "east", 
            F1PATH+"forest1.c","north",
            F1PATH+"forest21.c","south",
                 });
   items=({ 
     "road","A long dusty road that looks well used",
     "tracks","There are many deep gouges in the road",
     "hill","A hill rises up in the near distance",
     "valley","Mountains rise up on either side of a small valley",
     "mountains","Steep mountains that rise in the north and the south",
   });

        smell = "You smell dust and almost sneeze.";
    }
}


