//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
  "You have entered an intersection of trails. "+
    "As you glance into the distance you notice "+
    "that most of the countryside is sprinkled "+
    "with flowers and small bushes.  It looks "+
    "like a very peaceful land.\n";

    dest_dir=({
               "players/dragonn/area/ctr10", "north",
               "players/dragonn/area/ctr16", "west",
               "players/dragonn/area/ctr18", "east",
               "players/dragonn/area/ctr23", "south",
             });

    items=({ 
            "intersection","You are standing at an intesection of paths "+
                           "You will have to decide which one to follow",
            "flowers","You notice beautiful flowers protruding from the"+
                      " green grass",             
            "bushes","You spot some very small bushes in the distance",
            "grass","Long green grass that has grown widly in the sun "+
                    "for many years",
     "flower","A beautiful wild flower",
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
