
/* uc2 */

inherit "/room/room";
#include "../guild.h"

void reset(int flag)
{
    if (filter_live(this_object()) < 6)
    {
        CM("centipede");
        CM("centipede");
        CM("centipede");
        CM("centipede");
     }

     if (flag == 0)
     {
      short_desc = "In a cave under the monk chapel";
      long_desc = BS(
      "You have reaced a small crossing in the cave under "+
      "under the monk chapel. It smells awful like fresh "+
      "goblinshit. To the south the strange voices even "+
      "get louder. It just looks like that the centipedes "+
      "moved to this place to be more safe from the "+
      "strange creatures in the south.");
      
      items = ({
      "bottom","The bottom is wet and covered with moss",
      "ground","The bottom is wet and covered with moss",
      "walls","The walls are wet, heavy granite blocks",
      "wall","The walls are wet, heavy granite blocks",
      "moss","The moss has a light green colour",
      "ceiling","Some water is driping from the ceiling",
      "centipedes","As you look at them they quickly hide under a stone",
         });

      dest_dir = ({
                 PATH+"uc4","south",
                 PATH+"uc1","north",
                 PATH+"uc3","southwest",
                 PATH+"uc5","southeast",
                 });
     }
}

void init()
{
    ::init();
}

 
