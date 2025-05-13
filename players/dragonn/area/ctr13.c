//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
    "You notice a few trees and some flowers "+
    "sprinkling the landscape surrounding you. "+
    "Paths lead in every direction and you can "+
    "hear the chirping of a cricket in the far "+
    "distance.\n";
    dest_dir=({
    "players/dragonn/area/ctr06", "north",
           "players/dragonn/area/ctr14", "east",
           "players/dragonn/area/ctr12", "west",
          "players/dragonn/area/ctr20", "south",
             });

    items=({ 
            "trees","You notice some small oak trees growing around you",
            "paths","You notice many dirt trails leading off in various "+
                    "directions",
            "flowers","You spot a few beautiful yellow and white flowers",      
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
