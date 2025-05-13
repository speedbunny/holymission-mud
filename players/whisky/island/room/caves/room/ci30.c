
/* ci30 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (filter_live(this_object()) < 5)
     {
         CM("shaman");
         CM("shaman");
         CM("shaman");
         CM("chiefshaman");
         CM("boy");
     }
     if (flag == 0)
     {
        set_light(1);
        short_desc = "In the orc library";
        long_desc = BS(
        "You have entered a strange place in the orc caves. "+
        "On the walls you can see some inscriptions like "+
        "those ones mage have in thier spell books. All in all "+
        "This looks like a strange kind of library where the "+
        "orc shamans seem to learn their evil spells."+
        "To the east you can see a dark corridor.");
        items = 
        ({
         "bottom","The bottom is covered with blood",
         "inscription","You can't read the words they sound strange",
         "inscriptions","You can't read the words they sound strange",
         "corridor","You can see a dark corridor to the east",
         "ground","The bottom is covered with blood",
         "walls","The walls are made of stone",
        });
      }
     dest_dir = 
     ({
       PATH+"ci29","east",
     });
}
