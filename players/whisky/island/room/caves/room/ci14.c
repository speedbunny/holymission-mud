
/* ci14 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        set_light(0);
        short_desc = "The secret orc caves";
        long_desc = BS(
        "You are sneaking through the secret orc caves. To the north "+
        "the corridor leads further where you can hear some noises "+
        "coming from. The bottom is covered with moss and the air "+
        "here smells a bit sweet, like the odour of dead human "+
        "corpses. On the walls you see some big spots of blood. ");

        items = 
        ({
         "bottom","The bottom is covered with human bones",
         "ground","The bottom is covered with human bones",
         "walls","The walls are covered with human blood",
        });
      }
     dest_dir = 
     ({
       PATH+"ci13","south",
       PATH+"ci15","north",
     });
}
