//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
    "You are standing in the middle of an intersection "+
    "of dirt trails.  These paths lead all over the "+
    "countryside of Pavi.  You spot a house to your "+
    "distant southwest.\n";


    dest_dir=({
               "players/dragonn/area/ctr25", "north",
               "players/dragonn/area/ctr28", "west",
               "players/dragonn/area/ctr30", "east",
               "players/dragonn/area/ctr32", "south",

             });

    items=({ 
            "intesection","You are standing in the middle of a crosspaths."+
                          " The dirt path seem to travel all over the "+
                          "beautiful countryside of Pavi",
            "house","You spot a house to your southwest.  It might "+
                    "be a good place to rest for awhile",
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
