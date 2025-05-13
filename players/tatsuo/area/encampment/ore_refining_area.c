inherit "room/room";
#include "/players/tatsuo/area/tatsuo_defs.h"

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="The ore refining area",
        long_desc=
  "This is a large room which smells strongly of smoke.  Prisoners labor\n"+
  "with ore here, dumping, and crushing it with granite mortars to the\n"+
  "consistency of gravel.  Other workers wash the ground ore in a wooden\n"+
  "trough fed by water diverted from a nearby stream.\n";
   dest_dir=({
            CAMPPATH+"ore_refining_area2.c", "south",
	    CAMPPATH+"encampment9.c", "north", 
                 });
   items=({ 
     "smoke","Black sooty smoke fills the air",
     "granite","Strong stone with which the mortars are made",
     "trough","A long trough filled with water where laborers clean the ore",
     "ore","The silver ore is the consistency of gravel.",
     "mortars","Large tools made of solid granite used to crush ore.",
     "water","It looks dirty from washing all the ore.",
 });

        smell = "You smell smoke and almost sneeze.";
    }
}


