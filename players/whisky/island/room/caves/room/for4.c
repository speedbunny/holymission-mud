
/* for4 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        set_light(-1);
        short_desc = "In a dark mixed forest";
        long_desc = BS(
        "You are standing in a dark, mixed forest. The branches "+
        "are slighly moving in the wind. There are shadows on the "+
        "ground which make you shiver. With any step you make you "+
        "can hear the rustling of leaves. In the distance you can "+
        "hear the rumbling of the volcano.");

        items = 
        ({
         "bottom","The bottom is covered leaves and humus",
         "ground","The ground is covered leaves and humus",
         "volcano","The whole vulcano is surrounding you",
         "shrubbery","Some small bushes, nutration for animals",
         "trees","You see a lot of big old trees",
         "branches","The branches are moving in the wind",
        });
        dest_dir = 
        ({
         PATH+"for5","east",
         PATH+"for3","west",
         PATH+"prarie8","south",
         PATH+"for8","north",
        });
     }
}

void init()
{
     ::init();
}



