#include "/players/tamina/defs.h"
inherit "room/room";

reset(arg){

     set_light(-1);
     short_desc = "East Corridor ";
     long_desc = 
   "You continue along the East Corridor of the main building of Camelot.\n"+ 
   "Your light does not seem to be very effective in this gloom, as you\n"+
   "can see very little around you, nor very far into the distance.  But\n"+
   "you think that this must be close to where that tall tower should be...\n";

     dest_dir = ({
   CROOMS + "ecorridor2","north",
   CROOMS + "ecorridor","south",
     });

     items = ({
  "corridor",
"You can't see very much in the corridor because of the "+
"distinct lack of light",
  "walls",
"Across the stones are weird looking shapes made out of shadow, "+ 
"that almost seem alive in the gloom...",    
      });
   
    ::reset (arg);

    RPR("room/room");
}
