
/* cp10 */

inherit "/room/room";
#include "defs.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         set_light(1);
         short_desc = "At the gates";
         long_desc = 
         CASTLE+
         BS(
         "You are standing next to the gates of the castle. "+
         "Ravens are circling around in the air. To the north you "+
         "can see the entrancehall. Spiderwebs cover that old building."+
         "Sorry but the castle is closed.");
         items =
         ({
            "bottom","The bottom is covered with black, cold lava",
            "ground","The ground is covered with black, cold lava",
            "ruin","An old looking, wrecked castle",
            "building","An old looking, wrecked castle",
            "castle","An old looking, wrecked castle",
            "ravens","Ravens are circling high in the air",
            "spiderwebs","They cover the monument of the castle",
            "gates","strong wooden gates",
         });
         dest_dir =
         ({
             PATH+"cp9","east",
//             "/players/whisky/kantele/hall","south",
         });
      }
/*
      if (!present("castle ghost",this_object()))
      {
          call_out("my_msg",1);
          CM("ghost");
      }
*/
}

/*
void my_msg()
{
        tell_room(this_object(),
        "A strange shadow shimmers into existance.\n");
}

int move(string arg)
{
   object _ghost;

   _ghost = present("castle ghost",this_object());

    if (!arg)
         arg = query_verb();

    if (arg=="south" && _ghost && living(_ghost))
    {
        write("A ghostly hand, blocks your way to the south.\n");
        return 1;
    }
    return ::move(arg);
}
*/

