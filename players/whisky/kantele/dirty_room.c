
inherit "/room/room";
#include "defs.h"


void reset(int flag)
{
     if (!present("cleric",this_object())) 
         CM("priest");

     if (flag == 0)
     {
       dest_dir =
       ({
          PATH+"dirty_corridor","south",
       });

        short_desc =  "A small dirty room";
        long_desc = BS(
         "A small diry room, It looks like this room was made for "+
         "some reasons, but the reasons seems to be lost for you."); 
       
         items =
         ({
          "walls","The walls are made of red bricks",
          "ceiling","The ceiling is made of red bricks",
          "bottom","The bottom is made of fouly wood",
        });
    } 
}
