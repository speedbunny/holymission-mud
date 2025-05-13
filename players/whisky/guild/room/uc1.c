
/* uc1 */

inherit "/room/room";
#include "../guild.h"

void reset(int flag)
{
    if (filter_live(this_object()) < 4)
    {
        CM("centipede");
        CM("centipede");
        CM("centipede");
    }

     if (flag == 0)
     {
      short_desc = "In a cave under the monk chapel";
      long_desc = BS(
      "You have sneaked through the open hole into a small "+
      "cave under the monk chapel. It smells a bit fouly "+
      "here and the granite walls are covered with green "+
      "moss. You can hear strange voices coming from each "+
      "direction and you see some centipedes crawling on "+ 
      "bottom.");
      
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
                 PATH+"uc2","south",
                 PATH+"c1","up",
                 });
     }
 }

void init()
{
    ::init();
}

 
