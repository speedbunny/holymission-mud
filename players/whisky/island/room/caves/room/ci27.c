
/* ci27 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (filter_live(this_object()) < 8)
     {
        CM("baby");
        CM("baby");
        CM("baby");
        CM("female");
        CM("female");
        CM("female");
        CM("warrior");
        CM("guard");
        CM("guard");
     }
     if (flag == 0)
     {
        set_light(0);
        short_desc = "In the baby chamber of the orc caves";
        long_desc = BS(
        "You have entered a big chamber in the orc cave. "+
        "This is the place where the orcs get their babies "+
        "and care for them till they get strong fighters. "+
        "There are many curtains lying on the bottom, and it's "+
        "comfortly warm here. The bottom is covered with drops "+
        "of blood from the nutration the orc female bring thier "+
        "babies.");

        items = 
        ({
         "bottom","The bottom is covered with blood",
         "ground","The bottom is covered with blood",
         "walls","The walls are made of stone",
         "curtains","Old, but cosy curtains",
        });
      }
     dest_dir = 
     ({
       PATH+"ci26","east",
     });
}
