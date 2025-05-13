//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc= 
    "You spot an intersection ahead of you.  The "+
    "trails lead off in opposite ways but each is "+
    "surrounded by an enormous amount of vegetation.\n";

 
    dest_dir=({
               "players/dragonn/area/ctr19", "north",
               "players/dragonn/area/ctr24", "west",
               "players/dragonn/area/ctr26", "east",
               "players/dragonn/area/ctr29", "south",
             });

    items=({ 
            "intersection","You notice an intesection ahead of you",
            "trails","You spot dirt trails leading off to various "+
                     "destinations",
            "vegetation","You notice many different varietes of plants "+
                         "growing around you",
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
