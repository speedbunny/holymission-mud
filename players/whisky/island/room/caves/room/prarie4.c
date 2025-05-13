
/* prarie 4 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        set_light(1);
        short_desc = "In a prarie";
        long_desc = BS(
        "You are standing in a small open prarie in the volcano. "+
        "You are surrounded by the big peaks of these huge mountain. "+
        "Far to the northeast you can see a small, mixed forest. "+
        "There are some small bushes covering the ground and "+
        "many animals eating the good fresh grass covering "+
        "the bottom. High up in the air you see a big yellow "+
        "cloud of steam.");

        items = 
        ({
         "bottom","The bottom is covered with grass and bushes",
         "ground","The bottom is covered with grass and bushes",
         "volcano","The whole vulcano is surrounding you",
         "rocks","Big black rocks",
         "cloud","A big cloud of yellow steam",
         "forest","A beautiful, mixed forest to the north",
         "bushes","Some small green bushes, nutration for animals",
        });
        dest_dir = 
        ({
         PATH+"prarie3","west",
         PATH+"prarie9","northeast",
         PATH+"prarie8","north",
        });
     }
}

void init()
{
     ::init();
}



