//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc= 
    "You are standing amongst many trees and bushes. "+
    "As you glance around you notice many spotted "+
    "areas covered with wild flowers and small shrubs. "+
    "You notice paths leading in almost every direction.\n";

move_object(clone_object("players/dragonn/area/esmeralda"),this_object());
    dest_dir=({
               "players/dragonn/area/ctr21", "north",
               "players/dragonn/area/ctr26", "west",
               "players/dragonn/area/ctr31", "south",
             });

    items=({ 
            "paths","You notice many dirt paths leading in almost every "+
                    "direction",
            "bushes","You many bushes surrounding you",
            "flowers","You spot many beautiful flowers surrounding you",
            "shrubs","You notice that the entire area is almost covered "+
                     "with shrubs",
            "trees","You are standing amongst several large elm trees",
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
