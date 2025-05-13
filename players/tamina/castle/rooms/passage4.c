/*Secret Passage*/

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg){

     set_light(-2);
     short_desc = "Secret Passage ";
     long_desc = 
"You walk along the twisting and turning passage, as the dust continues\n"+ 
"to swirl around your feet...\n";

     dest_dir = ({
   CROOMS + "passage5","northeast",
   CROOMS + "passage3","west",
     });

     items = ({
  "dust",
"It moves very sluggishly as you walk through it",
      });

    ::reset (arg);

    RPR("room/room");
}

