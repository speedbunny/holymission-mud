/*  This is the North-East Tower  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

     set_light(0);
     short_desc = "North-East Tower ";
     long_desc =
"You stand before the arched entrance to the tallest of the towers of the\n"+
"King's castle.  All your light shows you at the moment, is stone steps\n"+ 
"leading upwards...\n"; 

     dest_dir = ({
   CROOMS + "ne_tower1", "up",
   CROOMS + "ecorridor2", "south",
     });
    
      items = ({
"stairs","Large stone steps ascending into the pitch-darkenss above",
      });

    ::reset (arg);

    RPR("room/room");
}
