
/* uc3 */

inherit "/room/room";
#include "../guild.h"

void reset(int flag)
{
    if (filter_live(this_object()) < 3)
        CM("goblin");

     if (flag == 0)
     {
      short_desc = "In a stinking goblincave";
      long_desc = BS(
      "You have reached the southern end of the granite cave. "+
      "The cavein to the soth seem to be a dead end, but "+
      "it seems that you hear the noise of a fast flowing "+
      "river southdown from you.");
      
      items = ({
      "bottom","The bottom is wet and covered with moss",
      "ground","The bottom is wet and covered with moss",
      "walls","The walls are wet, heavy granite blocks",
      "wall","The walls are wet, heavy granite blocks",
      "campfire",
      "The campfire is nearly burned out, but still glows a bit",
      "moss","The moss has a light green colour",
      "ceiling","Some water is driping from the ceiling",
      "centipedes","As you look at them they quickly hide under a stone",
         });

      dest_dir = ({
                 PATH+"uc4","north",
                 PATH+"uc3","northwest",
                 PATH+"uc5","northeast",
                 PATH+"uc8","south",
                 });
     }
  } 

void init()
{
    ::init();
}

 
