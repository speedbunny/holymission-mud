//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "Inside a Log House";
    long_desc=
     "This is yet another beautiful area "+
       "with many beautiful flowers lining the whole thing. "+
       "There are colorful leaves floating through "+
       "the air.  There are many shrubs all around "+
    "you swaying in the wind.\n";

    dest_dir=({
               "players/dragonn/area/ctr34", "north",
               "players/dragonn/area/ctr37", "west",

             });

    items=({ 

     "flowers","Many beautiful flowers",
     "shrubs","Small shrubs swaying in the wind",
     "leaves","Many different color leaves are floating through the "+                                    "air",
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
