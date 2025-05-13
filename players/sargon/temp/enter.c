#include "/players/thumper/def.h"
inherit "/room/room";

void reset(int arg) {
  if(!arg) {
   set_light(0);
    short_desc="The Caverns of the Hourons.";
long_desc =
              "You have stumbled into a vast cavern that has been "+
               "hidden from all since the very early days of Holy"+
               " mission. Time seems to have stood still in this"+
               " most unholy of places.  It is said that any who "+
               "houron. If you choose to enter here be warned, you"+
               " may find death sooner than you like.\n";
             
   dest_dir = ({
    "players/thumper/rooms/h1", "down"
        });

    items=({
       "walls","the walls are all black rock covered in moss",
       "floors","floors covered in dirt and debris.",
       "puddles of slime","sticky slime puddles.",
    });
  }
  ::reset(arg);
}
