
inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     if (flag == 0)
     {
         dest_dir =
         ({
            PATH+"kitiaras_livingroom","east",
         });
         short_desc = "In a strange room";
         long_desc = BS(
         "You are in a strange room, the room is small and totaly without " +
         "furniture of any kind. It looks like some kind of meditation " +
         "room, a large blackboard stands against the north wall.");

         items = ({
         "bottom","The bottom is made of fouly wood",
         "ceiling","The ceiling is made of red bricks",
         "walls","The walls are made of red bricks",
         "blackboard","There is a message on the blackboard:\n\n"+
         "Dear Kit !\n\n"+
         "Can you visit me tomorow ?\n"+
         "Please bring my gift !\n"+
         "unless you want to visit my pets!\n",
         });
    }
}
