//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
    "You are standing in the middle of a countryside "+
    "trail.  Ahead of you it bends and continues to "+
    "east and north.  Beautiful vegetation grows from "+
    "all sides of the dirt path.\n";
 
    dest_dir=({
               "players/dragonn/area/ctr29", "east",
               "players/dragonn/area/ctr24", "north",
             });

    items=({ 
            "trail","You are standing in the middle of a dirt trail. You "+
                   "notice flowers on all sides of you",
            "path","You notice flowers growing on all sides of the trail",
            "flowers","You spot many beautiful flowers surrounding you",
            "vegetation","You spot various kinds of flowers and plants "+
                         "surrounding you",
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
