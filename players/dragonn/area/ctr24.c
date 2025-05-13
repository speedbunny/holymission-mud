//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc= 
    "You are standing in the middle of an intersection "+
    "of trails with shrubs lining the sides of the path. "+
    "The land around you is bounded by beautiful vegetation. \n";

    dest_dir=({
               "players/dragonn/area/ctr18", "north",
               "players/dragonn/area/ctr23", "west",
               "players/dragonn/area/ctr25", "east",
               "players/dragonn/area/ctr28", "south",
             });

    items=({ 
            "intersection","You spot an intersection of paths.They "+
                           "lead in various directions",
            "shrubs","You notice shrubs surrounding both sides "+
                     "of the paths",
            "vegetation","You spot many different varietes of vegetation "+
                         "growing around you",
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
