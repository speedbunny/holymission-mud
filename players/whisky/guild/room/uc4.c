
/* uc3 */

inherit "/room/room";
#include "../guild.h"

void reset(int flag)
{
    if (filter_live(this_object()) < 6)
    {
        CM("goblin");
        CM("goblin");
        CM("goblin");
        CM("goblin");
     }

     if (flag == 0)
     {
      short_desc = "In a stinking goblincave";
      long_desc = BS(
      "You have reached the central part of this cave. "+
      "In the middle of this place is a small campfire and "+
      "some rests of those tasty looking centipedes are lying "+
      "around. To the east a very small corridor leads further "+
      "into a very small part of this cave.");
      
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
                 PATH+"uc2","north",
                 PATH+"uc3","west",
                 PATH+"uc5","east",
                 PATH+"uc7","south",
                 });
     }
  }

int query_property(string arg)
{
    if (arg=="has_fire")
       return 1;
    return 0;
}

void light_text(string arg)
{
   say(this_player()->query_name()+" lights "+arg+" on the glowing campfire.\n",
       this_player());
   write("You light "+arg+" on the glowing campfire.\n");
}

void init()
{
    ::init();
}

 
