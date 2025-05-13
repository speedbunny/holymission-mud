//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
    "You are standing in the middle of a dirt trail. "+
    "A few large trees hang over you and there are "+
    "leaves scattered all around you.  You hear the "+
    "chirping of crickets in the distance.\n";
 
    dest_dir=({
               "players/dragonn/area/ctr08", "west",
     "players/dragonn/area/ctr02", "north",
               "players/dragonn/area/ctr10", "east",
               "players/dragonn/area/ctr16", "south",
             });

    items=({ 
            "trail","You are standing on a dirt trail in the middle of "+
                    "beautiful countryside of Pavi. You notice some "+
                    "leaves surrounding you",
             "trees","You notice a few large trees with their branches "+
                     "surrounding you",
             "leaves","You notice many leaves scattered all around you",
             
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
