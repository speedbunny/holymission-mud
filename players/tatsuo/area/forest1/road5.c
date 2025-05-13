inherit "room/room";

#include "/players/tatsuo/area/tatsuo_defs.h"

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="A long road through a small valley",
        long_desc=
            "This road is well worn with the grooves of cart tracks.  The\n" +
	    "road is fairly level, making for easy travelling.  A dense forest\n"+
	    "surrounds the road to the north and the south, but you see a\n"+
	    "clearing to your west.\n";
   dest_dir=({
            F1PATH+"road6.c", "west",
	    F1PATH+"road4.c", "east", 
	    F1PATH+"forest6.c","north",
            F1PATH+"forest26.c","south",
                 });
   items=({ 
     "road","A long dusty road that looks well used",
     "tracks","There are many deep gouges in the road",
     "hill","This hill, while not too large is rather steep",
     "valley","Mountains rise up on either side of a small valley",
     "mountains","Steep mountains that rise in the north and the south",
   });

        smell = "You smell dust and almost sneeze.";
    }
}


