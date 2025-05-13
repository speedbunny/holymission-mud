
/* ci25 */

inherit "/room/room";
#include "../caves.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        set_light(0);
        short_desc = "Up the stairs";
        long_desc = BS(
        "You are walking carefully up the big wooden stairway "+
        "in the secret orc chambers. When you look down you see "+
        "some light entering through eastern holes in the walls. "+
        "But to the north the corridor gets darker again and you "+
        "can hear the strange grunting noises getting louder.");

        items = 
        ({
         "bottom","The bottom is covered with human bones",
         "ground","The bottom is covered with human bones",
         "walls","The walls are covered with human blood",
         "stairway","You see a small wooden stairway leading up",
         "holes","You see some tiny holes where beams of light come in",
         "hole","You see some tiny holes where beams of light come in",
        });
      }
     dest_dir = 
     ({
       PATH+"ci26","north",
       PATH+"ci24","down",
     });
}
