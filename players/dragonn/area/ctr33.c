//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
    "You have arrived at a crossroad.  There "+
    "are four ways in which to go.  Each trail "+
    "is covered with trees and shrubs. "+
    "All the trails are beautiful and "+
    "fantastic.\n";
    dest_dir=({
               "players/dragonn/area/ctr30", "north",
               "players/dragonn/area/ctr32", "west",
               "players/dragonn/area/ctr34", "east",
               "players/dragonn/area/ctr37", "south",

             });

move_object(clone_object("players/dragonn/area/esmeralda"),this_object());
    items=({ 
      "crossroad","You are standing at a crossroad.  Dirt paths "+
        "lead in every direction and they are surrounded by flowers",
      "trees","You notice large elm trees all around you",
      "shrubs","You spot small shrubs surrounding you",

          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
