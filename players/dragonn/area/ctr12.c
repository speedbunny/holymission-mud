//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
  "You are traveling on a dirt path that continues "+
    "in every direction.  To your southwest you notice "+
    "a small pond that seems to be a haven for waterfowl.\n";

    dest_dir=({
               "players/dragonn/area/ctr05", "north",
               "players/dragonn/area/ctr11", "west",
               "players/dragonn/area/ctr13", "east",
               "players/dragonn/area/ctr19", "south",
             });

    items=({ 
            "pond","You notice that the small pond has crystal clear water",
     "water","You see a crystal clear water",
            "path","You are standing in the middle of a dirt path",            
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
