
/* ci8 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (filter_live(this_object()) < 2)
     {
        CM("shaman");
        CM("shaman");
        CM("peasant");
        CM("peasant");
        CM("warrior");
        CM("warrior");
     }
     if (flag == 0)
     {
        set_light(0);
        short_desc = "In the orc Caves";
        long_desc = BS(
        "You have entered the sleeping caves of the orcs. "+
        "It looks like a bigger hallway where the corners "+
        "are covered with wooly curtains. As you came in  "+
        "you saw some orcs snoring loudly and some others fucking "+
        "each other and grunting loudly. As they heared you "+
        "one shouts wake up you assholes !");

        items = 
        ({
         "bottom","The bottom is covered with human bones",
         "ground","The bottom is covered with human bones",
         "walls","The walls are covered with human blood",
         "curtains","The curtains are made of wool",
        });
        dest_dir = 
        ({
         PATH+"ci12","north",
         PATH+"ci7","east",
        });
     }
}


