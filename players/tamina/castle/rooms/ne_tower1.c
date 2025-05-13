/*This is the 1st floor of the NE-Tower */
#include "/players/tamina/defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

     set_light(-2);
     short_desc = "1st Floor of the NE Tower";
     long_desc = 
   "You climb up...\n"+ 
   "                                   ...up...\n"+
   "\n"+
   "                            ...up...\n"+
   "\n"+
   "                     ...up...\n"+ 
   "\n"+
   "             ...up...\n"+
   "The stairs lead ever upwards it seems...\n";

     dest_dir = ({
   CROOMS + "ne_tower","down",
   CROOMS + "ne_tower3","up",    
     });
}
