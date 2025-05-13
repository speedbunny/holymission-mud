inherit "room/room";

#define FPATH "/players/tatsuo/area/rooms/"
#include "/players/tatsuo/area/tatsuo_defs.h"

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="The supervisor's office",
        long_desc=
  "Maps of the mine and proposed excavations are posted on every wall.  A\n"
  "large wooden table and eight chairs are in the center of the room.  On\n"+
  "the west wall are two four foot shelves with several scrolls of mine\n"+
  "and rock data in wolfen script.  Below these shelves is a cabinet.\n";
   dest_dir=({
            CAMPPATH+"supervisor_quarters1.c","north",
         });
   items=({ 
  "ceiling","It is close to 10 feet high",
  "wall","It was chipped out of stone",
  "scrolls","Wolfen script is written upon them.  You are unable to read them",
  "cabinet","A large wooden cabinet with a lock on it",
  "chairs","Eight sturdy wooden chairs surround the table in the center of the room",
  "script","You are unable to read it",
  "maps","Maps of the mine and proposed excavations",
  "shelves","Four foot shelves that look like they are going to fall down",
  });

        smell = "You smell nothing special.";
    }
}



