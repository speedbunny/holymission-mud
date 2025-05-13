inherit "room/room";

#include "/players/blade/area/blade_defs.h"

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="A narrow tunnel",
        long_desc=
  "A narrow tunnel in the ground.  It is high enough so that you do not\n"+
  "bump your head, but you feel closed in anyway.  A torch on the wall\n"+
  "lights the corridor.\n";
   dest_dir=({
            CAMPPATH+"encampment7.c","south",
	    CAMPPATH+"legionnaire_corridor2.c","north",
         });
   items=({ 
  "torch","A sputtering torch used to light the dim corridor",
  "tunnel","A narrow dim tunnel in the ground",
  "ceiling","It is close to 10 feet high",
  "corridor","A narrow dim tunnel in the ground",
  "wall","It was chipped out of stone",
  });

   property=({"has_fire"});

        smell = "You smell an oily torch.";
    }
}



