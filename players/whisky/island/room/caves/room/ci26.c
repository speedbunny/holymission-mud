
/* ci26 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        set_light(0);
        short_desc = "In the secret orc chambers";
        long_desc = BS(
        "You are sneaking through the secret orc caves. "+
        "To the south you see a stairway and to the west "+
        "you can hear grunting voices like the voices of "+
        "pigbabies. To the north the dark corridor leads "+
        "further. The bottom is covered with drops of blood "+
        "like orcs have brought up some food to this place.");

        items = 
        ({
         "bottom","The bottom is covered with blood",
         "ground","The bottom is covered with blood",
         "walls","The walls are made of stone",
         "stairway","You see a small wooden stairway leading down",
        });
      }
     dest_dir = 
     ({
       PATH+"ci28","north",
       PATH+"ci25","south",
       PATH+"ci27","west",
     });
}
