//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
    "You are standing in a small opening of the "+
    "path.  You notice the remains of a small "+
    "campfire lying before you in the center of the "+
    "opening.  Wild flowers dot the beautiful "+
    "landscape all around you.\n";
    dest_dir=({
               "players/dragonn/area/ctr13", "west",
               "players/dragonn/area/ctr07", "north",
               "players/dragonn/area/ctr21", "south",
             });

    items=({ 
            "campfire","You notice the remains of an old campfire. "+
    "It has a few pieces of sharred wood in the center "+
                       "of it",
            "opening","You are standing in the middle of an opening in "+
                      "the path. You spot something in the centre of it",             
            "flowers","You spot beautiful white flowers surrounding you",
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
