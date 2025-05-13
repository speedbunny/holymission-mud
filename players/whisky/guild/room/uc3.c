
/* uc3 */

inherit "/room/room";
#include "../guild.h"

void reset(int flag)
{
    if (filter_live(this_object()) < 4)
    {
        CM("goblin");
        CM("goblin");
    }

     if (flag == 0)
     {
      short_desc = "In a stinking goblincave";
      long_desc = BS(
      "You have reached a the western part of this granite cave. "+
      "Water is driping from the ceiling and rumors can be "+
      "heared to the south and east. To the north the cave "+
      "is leading back to the hole under the monk chapel."); 
      
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
                 PATH+"uc2","northeast",
                 PATH+"uc7","southeast",
                 PATH+"uc4","east",
                 });
     }
 }

void init()
{
    ::init();
}

 
