//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
    "You have just entered a small opening with "+
    "trails leading in all directions.  You notice "+
    "large trees with branches stretching above "+
    "you and leaves falling to the ground ahead of "+
    "you.\n";



    dest_dir=({
               "players/dragonn/area/ctr26", "north",
               "players/dragonn/area/ctr29", "west",
               "players/dragonn/area/ctr31", "east",
               "players/dragonn/area/ctr33", "south",

             });

    items=({ 
        "opening","You are standing in the opening",
        "trees","You notice the branches of a "+
                "tall elm tree stretching above you",
        "leaves","You notice a pile of leaves ahead of you",


          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
