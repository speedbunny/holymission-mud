
/* prarie 7 */

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
        "You are standing in a small open prarie next to some firs. "+
        "You are surrounded by the big peaks of these huge mountain. "+
        "To the north you can enter a dark mixed forest. "+
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
         "firs","You see some huge, firs",
        });
        dest_dir = 
        ({
         PATH+"prarie8","east",
         PATH+"prarie6","west",
         PATH+"prarie3","south",
         PATH+"for3","north",
        });
     }
}

void init()
{
     ::init();
}



