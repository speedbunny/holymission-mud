//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc= 
    "You notice that the trail bends ahead of you. "+
    "Paths go to the east and to the north "+
    "while small trees and flowers cover most of the "+
    "area around you.\n";
    dest_dir=({
               "players/dragonn/area/ctr17", "north",
               "players/dragonn/area/ctr24", "east",
             });

    items=({ 
            "flowers","You spot beautiful flowers growing all around you",
            "trees","You notice small trees everywhere you look",
            "path","You are standing in the middle of a dirt path",
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
