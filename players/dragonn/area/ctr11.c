//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
   "There are many beautiful wild flowers "+
    "and small trees dotting the landscape "+
    "between you and the horizon.  You see "+
    "a small pond to your southeast that "+
    "might be a good place to fish.\n";


    dest_dir=({
               "players/dragonn/area/ctr04", "north",
               "players/dragonn/area/ctr10", "west",
               "players/dragonn/area/ctr12", "east",
               "players/dragonn/area/ctr18", "south",
             });

    items=({ 
            "pond","You notice plenty of fish swimming in the crystal "+
                   "waters of the pond",
            "fish","You notice a three pound trout swimming next to the "+
                   "shore",
            "flowers","You spot many gorgeous flowers surrounding you",
            "trees","As you glance around you notice a few small trees "+
                    "growing up from the beautifull grass",
            "horizon","You notice the sun above the horizon",
             
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
