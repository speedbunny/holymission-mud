//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg);
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
 "You are traveling on a path that continues to "+
    "the west and east.  You notice a small dirt "+
    "trail leading south with shrubs growing off to "+
    "the sides of it.\n";


    dest_dir=({
               "players/dragonn/area/ctr02", "west",
               "players/dragonn/area/ctr04", "east",
               "players/dragonn/area/ctr10", "south",
             });

    items=({ 
   "flowers","Small yellow and red flowers",
            "path","You are standing on a dirt path that is in the middle "+
            "of the beautiful countryside of Pavi",
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
