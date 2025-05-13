/*This is the 1st floor of the NE-Tower */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

     set_light(-1);
     short_desc = "1st Floor of the NE Tower ";
     long_desc = 
   "You go back down the stairs...\n"+ 
   "                             ...down...\n"+
   "\n"+
   "                                       ...down...\n"+
   "\n"+
   "                                                 ...down...\n"+ 
   "\n"+
   "                                                          ...down...\n"+
   "It didn't seem as though there were this many stairs when you were\n"+ 
   "going up them...\n";

     dest_dir = ({
   CROOMS + "ne_tower","down",
   CROOMS + "ne_tower3","up",    
     });

    ::reset (arg);

    RPR("room/room");
}
