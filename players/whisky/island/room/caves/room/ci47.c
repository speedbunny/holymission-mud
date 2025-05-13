
/* ci47 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        set_light(0);
        short_desc = "Inside a huge doorway";
        long_desc = BS(
        "You are standing inside a huge doorway. To the north "+
        "you can see some big shadows and you can hear some "+
        "noises coming from. They make you shiver. Maybe the "+
        "best idea is to run back down the stairway. On the "+
        "gateway you can see and inscription reading: "+
        "\n                Stay out or die !");

        items = 
        ({
         "bottom","The bottom is covered with blood",
         "ground","The bottom is covered with blood",
         "walls","The walls are made of stone",
         "spots","You see big spots of human blood",
         "blood","You see big spots of human blood", 
         "stairway","A small stone stairway leading down",
         "doorway","A big stone doorway",
         "moss","Green wet moss",
         "shadows","The shadows of huge creatures",
        });
      }
     dest_dir = 
     ({
       PATH+"ci48","north",
       PATH+"ci46","down",
     });
}


