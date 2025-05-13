
/* uc3 */

inherit "/room/room";
#include "../guild.h"

void reset(int flag)
{
    if (!present("goblin chief",this_object()))
         CM("goblin_ch");

    if (filter_live(this_object()) < 3)
    {
        CM("goblin");
        CM("goblin");
     }

     if (flag == 0)
     {
      short_desc = "In a stinking goblincave";
      long_desc = BS(
      "You have reached the eastern part of this goblin cave."+
      "The corridor ends here in a small cave in which looks like "+
      "a store for the goblins treasure. You see a glittering "+
      "emanating from this corner, but it doesn't seem as if this "+
      "place is very safe.");
      
      items = ({
      "bottom","The bottom is wet and covered with moss",
      "ground","The bottom is wet and covered with moss",
      "cavein","It seems to be the treasury of the goblins",
      "walls","The walls are wet, heavy granite blocks",
      "wall","The walls are wet, heavy granite blocks",
      "campfire",
      "The campfire is nearly burned out, but still glows a bit",
      "moss","The moss has a light green colour",
      "ceiling","Some water is driping from the ceiling",
      "centipedes","As you look at them they quickly hide under a stone",
         });

      dest_dir = ({
                 PATH+"uc2","northwest",
                 PATH+"uc7","southwest",
                 PATH+"uc4","west",
                 PATH+"uc6","east",
                 });
     }
  }


void init()
{
    ::init();
}


status move(string arg)
{
  object gob;

  gob=present("goblin",this_object());

    if (!arg)
         arg = query_verb();

    if ( arg == "east" && objectp(gob) && living(gob) )
    {
        write("A Goblin blocks you the way.\n");
        say(this_player()->query_name()+" tries to go east "+
            "but is blocked by a goblin.\n",this_player());
        return 1;
     }
   return ::move(arg);
}
        
