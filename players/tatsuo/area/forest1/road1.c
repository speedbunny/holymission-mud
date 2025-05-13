inherit "room/room";

#include "/players/tatsuo/area/tatsuo_defs.h"

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="A long road through a small valley",
        long_desc=
            "This road is well worn with the grooves of cart tracks.  It\n" +
	    "rises over a small hill in the near distance.\n" +
"Welcome to my area.  It's pretty new, so if you find\n" +
"any bugs, be sure to use commands <bug> or <typo>.\n" +
"Otherwise, enjoy the area.  -- Blade (Area being serviced by Blade's old pal, Tatsuo)\n";
   dest_dir=({
            F1PATH+"road2.c", "west",
             "room/orc_valley/valley12", "east",
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


