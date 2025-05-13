/* Wardrobe - Passage */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg){

     set_light(0);
     short_desc = "Wardrobe ";
     long_desc = 
   "You find yourself in a very small, dark passage, with stairs leading\n"+ 
   "downwards into the deeper gloom...\n";

     dest_dir = ({
   CROOMS + "ne_tower3","out",
   CROOMS + "wardrobe2","down",
     });

     items = ({
  "stairs",
"Small wooden stairs leading downwards from where you are", 
     });

    ::reset (arg);

    RPR("room/room");
}

