//Dragonn-coderrrrio...'96
inherit "room/room";

void reset(int arg) {
::reset(arg); 
if(arg) return;

    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=   
    "You have entered an opening in the path. "+
    "Wild flowers completely surround the trail "+
    "to make a half circle.  It looks like it "+
    "could be the works of the gods.\n";
move_object(clone_object("players/dragonn/area/esmeralda"),this_object());
    dest_dir=({
               "players/dragonn/area/ctr15", "north",
             });

    items=({ 
            "flowers","You notice yellow and white flowers protruding"+
                      " from the earth",
            "opening","You are standing in the middle of an opening "+
                      "in the path. It opens into a half circle",
          });
/*
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });
*/
}
