inherit "room/room";

#include "/players/tatsuo/area/tatsuo_defs.h"

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="A long road through a small valley",
        long_desc=
  "This road is well worn with the grooves of cart tracks.  The\n" +
  "road is fairly level, making for easy travelling.  A sizable\n"+
  "clearing lies to your south.  In the clearing you see some tents\n"+
  "and some small buildings.  Loud noises are coming from the closest\n"+
  "tent to the south.\n";
   dest_dir=({
            F1PATH+"road8.c", "west",
	    F1PATH+"road6.c", "east", 
	    F1PATH+"tavern_tent.c","south"
                 });
   items=({ 
     "road","A long dusty road that looks well used",
     "tracks","There are many deep gouges in the road",
     "tent","Its too far away to see any details",
     "buildings","They are too far away to see any details",
     "clearing","A newly made clearing lies to your south",
     "valley","Mountains rise up on either side of a small valley",
     "mountains","Steep mountains that rise in the north and the south",
   });

        smell = "You smell alchol and the smell of sweat.";
    }
}


