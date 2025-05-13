//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
    "You are at the intersection of many countryside trails. "+
    "You notice small bushes and beautiful wild flowers all "+
    "around you.  You hear the faint rustle of leaves in the "+
    "distance.\n";

    dest_dir=({
               "players/dragonn/area/ctr03", "north",
               "players/dragonn/area/ctr09", "west",
               "players/dragonn/area/ctr11", "east",
               "players/dragonn/area/ctr17", "south",
             });

    items=({ 
            "bushes","You notice a few bushes scattered around you",
            "intersection","A crossing of many different trails",
            "flowers","You spot many wild flowers growing all around you",
             
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
