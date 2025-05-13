//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
  "You are traveling on a dirt path that intersects "+
    "with another trail.  To your northwest you notice "+
    "a small beautiful pond that seems to be a haven "+
    "for various species of waterfowl.  Vegetation "+
    "grows from the edge of the pond.\n";

move_object(clone_object("players/dragonn/area/esmeralda"),this_object());
  
    dest_dir=({
               "players/dragonn/area/ctr12", "north",
               "players/dragonn/area/ctr18", "west",
               "players/dragonn/area/ctr20", "east",
               "players/dragonn/area/ctr25", "south",
             });

    items=({ 
            "path","You are standing in the middle of a dirt trail",
            "vegetation","The vegetation moslty consists of various kinds"+
                         " of flowers",             
            "pond","You notice how crystal clear water is in the pond",
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
