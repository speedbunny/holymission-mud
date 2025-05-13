#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg){

     set_light(0);
     short_desc = "West Corridor ";
     long_desc = 
   "This is the corridor in the West Wing of the Castle of King Arthur.\n"+ 
   "As you walk along it, in near complete darkness, your skin starts \n"+
   "to crawl, as a foul odour hits your nostrils...  You hope that it \n"+
   "is only rotten meat in the kitchen.  To the west, another passage\n"
   "branches off into the West Wing of Camelot.\n";

     dest_dir = ({
   CROOMS + "wwing1","south",
   CROOMS + "wwing2","west",
   CROOMS + "wcorridor1","north",
     });

     items = ({
   "tapestires", 
"The bits that you can see depict worthy triumphs of the "+
"noble King Arthur, and his magnificent Knights", 
   "corridor", 
"You can't see very much in the corridor because of the "+
"distinct lack of light",
        });

     smell = "The putrid stench of rotten flesh assails your nostrils";

    ::reset (arg);

    RPR("room/room");
}

