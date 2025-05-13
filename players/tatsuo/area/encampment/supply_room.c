inherit "room/room";

#include "/players/tatsuo/area/tatsuo_defs.h"

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="The first level mine storage room",
        long_desc=
"A small storeroom filled with soap, rags, slave clothes, rope, six dozen \n"+
"wooden spikes and hammers, three empty trunks, and an empty five gallon\n"+
"kettle.\n";
   dest_dir=({
            CAMPPATH+"legionnaire_corridor4.c", "east",
                 });
   items=({ 
   "soap","Many pieces of lye soap",
   "rags","Dirty rags in a large pile",
   "slave clothes","Clothes made out of very cheap fabric",
   "rope","Ten 50ft lengths of rope",
   "spikes","A pile of large spikes",
   "hammers","A pile of sturdy hammers",
   "trunks","Heavy trunks that have nothing in them",
   "kettle","It looks like a soup kettle",
   });

        smell = "You smell nothing special.";
    }
}



