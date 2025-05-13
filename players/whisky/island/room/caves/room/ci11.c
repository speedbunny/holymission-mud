
/* ci11 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (filter_live(this_object()) < 4)
     {
         CM("shaman");
         CM("shaman");
         CM("shaman");
         CM("warrior");
         CM("warrior");
     }
     if (!present("orc chiefshaman",this_object()))
         CM("chiefshaman");
     if (flag == 0)
     {
        set_light(0);
        short_desc = "By the Altar";
        long_desc = BS(
        "You are standing in a big hallway in the Orc caves. "+
        "At the northern end of the hallway you see a big altar. "+
        "You can imagine that this altar is built for Cyric the "+
        "evil god. Dead corpses are lying beside the altar "+
        "with severed heads, penises, breasts and torn out hearts. "+
        "The whole room is painted with human blood.");

        items = 
        ({
         "bottom","The bottom is covered with human bones",
         "ground","The bottom is covered with human bones",
         "walls","The walls are covered with human blood",
         "altar","A hudge black altar made of stone",
         "heads","Ugghh bloody human corpse parts",
         "breasts","Ugghh bloody human corpse parts",
         "penis","Ugghh bloody human corpse parts",
        });
        dest_dir = 
        ({
         PATH+"ci10","south",
        });
     }
}


