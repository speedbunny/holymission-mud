//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
 "You are traveling on a trail that continues "+
    "west and east.  You see another path leading "+
    "south and wild flowers dotting the surrounding "+
    "landscape.\n";
    dest_dir=({
               "players/dragonn/area/ctr05", "west",
               "players/dragonn/area/ctr07", "east",
               "players/dragonn/area/ctr13", "south",
             });

move_object(clone_object("players/dragonn/area/esmeralda"),this_object());
    items=({ 
             "trail","You are standing on a dirt trail surrounded by "+
                     "very beautiful grass and shrubs. Wild flowers "+
                     "sprinkle the landscape",
   "flowers","You notice beautiful wild flowers surrounding "+
 "you. They seem to be growing very quickly",
             
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
