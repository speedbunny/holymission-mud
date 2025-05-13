inherit "room/room";

#include "/players/tatsuo/area/tatsuo_defs.h"

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="A long road through a small valley",
        long_desc=
  "This road is well worn with the grooves of cart tracks.  The\n" +
  "road is fairly level, making for easy travelling.  A dense forest\n"+
  "surrounds the road to the south.  To the north you see a small tent.\n";
   dest_dir=({
            F1PATH+"road7.c", "west",
	    F1PATH+"road5.c", "east", 
	    F1PATH+"shop_tent.c","north",
            F1PATH+"forest_t1.c","south",
                 });
   items=({ 
     "road","A long dusty road that looks well used",
     "tracks","There are many deep gouges in the road",
     "grooves","These must have been made by a heavy cart",
     "tent","A small tent made of cloth",
     "valley","Mountains rise up on either side of a small valley",
     "mountains","Steep mountains that rise in the north and the south",
  });

        smell = "You smell nothing special";
    }
}


