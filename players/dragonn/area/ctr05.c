//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
    "You are walking on a path in the countryside "+
  "of Pavi.  You notice small trees and bushes "+
    "growing with the healthy grass all around you. "+
    "You hear the faint songs of birds singing in "+
    "the distance.\n";

move_object(clone_object("players/dragonn/area/esmeralda"),this_object());

    dest_dir=({
               "players/dragonn/area/ctr04", "west",
               "players/dragonn/area/ctr06", "east",
               "players/dragonn/area/ctr12", "south",
             });

    items=({ 
             "trees","You notice a few small trees sprinkled "+
                      "acros the beautiful landscape",
            "grass","You notice how green the grass is. The grass "+
                    "is very tall and therefore it also must be very "+
                    "healthy",
             "path","You are standing on a dirt path. "+
                   "You notice grass surrounding the entire trail",
            "bushes","You spot a bunch of large bushes dotting the "+
                "grass around you",
             
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
