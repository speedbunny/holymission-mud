inherit "room/room";

#include "/players/tatsuo/area/tatsuo_defs.h"

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="A long road through a small valley",
        long_desc=
  "This road is well worn with the grooves of cart tracks.  The\n" +
  "road is fairly level, making for easy travelling.  A large\n"+
  "palisade lies to the north.\n";
   dest_dir=({
            F2PATH+"road9.c", "west",
	    F1PATH+"road7.c", "east", 
	    F1PATH+"forest36.c","south",
                 });
   items=({ 
     "road","A long dusty road that looks well used",
     "tracks","There are many deep gouges in the road",
     "palisade","A large palisade with a wolfen guard standing on top",
     "valley","Mountains rise up on either side of a small valley",
     "mountains","Steep mountains that rise in the north and the south",
 });

        smell = "You smell dust from the road.";
    }
}


