// Mangla: Removed the crack stuff since river gone.
/* uc3 */

inherit "/room/room";
#include "../guild.h"

void reset(int flag)
{
    if (filter_live(this_object()) < 3)
    {
        CM("centipede");
        CM("centipede");
        CM("centipede");
    }

     if (flag == 0)
     {
      short_desc = "At the southern end of the goblin cave";
      long_desc = BS(
      "You are standing in front of a huge wall made of granite. "+
      "This seems to be the dead end. Deep under you you can hear "+
      "the noise of a fast flowing river. The only way back seems "+
      "to the north.");
      
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
                 PATH+"uc7","north",
                 });
     }
 }

void init()
{
    ::init();
}

